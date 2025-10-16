# SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

# Detect if we are doing a standalone build of the bindings, using an external trintrin
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(TRINTRIN_PYTHON_BINDINGS_BUILD_STANDALONE ON)
  set(TRINTRIN_COMPILE_PYTHON_BINDINGS ON)
else()
  set(TRINTRIN_PYTHON_BINDINGS_BUILD_STANDALONE FALSE)
endif()

if(TRINTRIN_PYTHON_BINDINGS_BUILD_STANDALONE)
  cmake_minimum_required(VERSION 3.16)
  project(trintrinBindings)
  find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
  find_package(pybind11 REQUIRED)
  find_package(trintrin REQUIRED)
endif()

if(TRINTRIN_COMPILE_PYTHON_BINDINGS)
    find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
    find_package(pybind11 REQUIRED)

    set(NEW_LINE "\n")

    option(TRINTRIN_DETECT_ACTIVE_PYTHON_SITEPACKAGES
        "Do you want BLF to detect and use the active site-package directory? (it could be a system dir)"
        FALSE)

    if(NOT DEFINED TRINTRIN_PYTHON_INSTALL_DIR)
      if(TRINTRIN_DETECT_ACTIVE_PYTHON_SITEPACKAGES)
        set(TRINTRIN_PYTHON_INSTALL_DIR ${Python3_SITELIB})
      else()
        execute_process(COMMAND ${Python3_EXECUTABLE} -c "import os;import sysconfig;relative_site_packages = sysconfig.get_path('purelib').replace(sysconfig.get_path('data'), '').lstrip(os.path.sep);print(relative_site_packages)"
                        OUTPUT_VARIABLE _PYTHON_INSTDIR)
        string(STRIP ${_PYTHON_INSTDIR} _PYTHON_INSTDIR_CLEAN)
        set(TRINTRIN_PYTHON_INSTALL_DIR ${_PYTHON_INSTDIR_CLEAN})
      endif()
    endif()
    set(PYTHON_INSTDIR ${TRINTRIN_PYTHON_INSTALL_DIR}/trintrin)


    # Folder of the Python package within the build tree.
    # It is used for the Python tests.
    set(TRINTRIN_PYTHON_PACKAGE "${CMAKE_BINARY_DIR}/trintrin")

    # Add the bindings directory
    add_subdirectory(python)

    # Create the __init__.py file
    file(WRITE ${TRINTRIN_PYTHON_PACKAGE}/__init__.py "")

    # If we are on Windows and BUILD_SHARED_LIBS is ON, handle the fact that
    # the Python interpreter does not look into PATH to find dll (see https://docs.python.org/3.8/library/os.html#os.add_dll_directory)
    if(WIN32 AND BUILD_SHARED_LIBS)
        if(IS_ABSOLUTE PYTHON_INSTDIR)
            set(PYTHON_FULL_INSTDIR "${PYTHON_INSTDIR}")
        else()
            set(PYTHON_FULL_INSTDIR "${CMAKE_INSTALL_PREFIX}/${PYTHON_INSTDIR}")
        endif()
        file(RELATIVE_PATH RELATIVE_PATH_BETWEEN_INIT_PY_AND_DLL_DIRECTORY ${PYTHON_FULL_INSTDIR} ${CMAKE_INSTALL_FULL_BINDIR})
        file(APPEND "${TRINTRIN_PYTHON_PACKAGE}/__init__.py" "import os${NEW_LINE}")
        file(APPEND "${TRINTRIN_PYTHON_PACKAGE}/__init__.py" "library_dll_path = os.path.join(os.path.dirname(__file__),'${RELATIVE_PATH_BETWEEN_INIT_PY_AND_DLL_DIRECTORY}')${NEW_LINE}")
        file(APPEND "${TRINTRIN_PYTHON_PACKAGE}/__init__.py" "# Avoid to call add_dll_directory if not necessary,${NEW_LINE}")
        file(APPEND "${TRINTRIN_PYTHON_PACKAGE}/__init__.py" "# for example if the library to find are already found in the proper location in a conda environment${NEW_LINE}")
        file(APPEND "${TRINTRIN_PYTHON_PACKAGE}/__init__.py" "if(library_dll_path != os.path.join(os.environ.get('CONDA_PREFIX', ''),'Library','bin') and library_dll_path != os.path.join(os.environ.get('CONDA_PREFIX', ''),'bin')):${NEW_LINE}")
        file(APPEND "${TRINTRIN_PYTHON_PACKAGE}/__init__.py" "    if(os.path.exists(library_dll_path)):${NEW_LINE}")
        file(APPEND "${TRINTRIN_PYTHON_PACKAGE}/__init__.py" "        os.add_dll_directory(library_dll_path)${NEW_LINE}")

        # For running tests, we need to add also the path where the dependecies are installed.
        # We add yarp to update the dll path for the tests.
        file(APPEND "${TRINTRIN_PYTHON_PACKAGE}/__init__.py" "import yarp${NEW_LINE}")


    endif()

    file(APPEND "${TRINTRIN_PYTHON_PACKAGE}/__init__.py" "from .bindings import *${NEW_LINE}")

    # Install the __init__.py file
    install(FILES "${TRINTRIN_PYTHON_PACKAGE}/__init__.py"
            DESTINATION ${PYTHON_INSTDIR})

    # Install pip metadata files to ensure that trintrin installed via CMake is listed by pip list
    # See https://packaging.python.org/specifications/recording-installed-packages/
    # and https://packaging.python.org/en/latest/specifications/core-metadata/#core-metadata
    option(TRINTRIN_PYTHON_PIP_METADATA_INSTALL "Use CMake to install Python pip metadata. Set to off if some other tool already installs it." ON)
    mark_as_advanced(TRINTRIN_PYTHON_PIP_METADATA_INSTALL)
    set(TRINTRIN_PYTHON_PIP_METADATA_INSTALLER "cmake" CACHE STRING "Specify the string to identify the pip Installer. Default: cmake, change this if you are using another tool.")
    mark_as_advanced(TRINTRIN_PYTHON_PIP_METADATA_INSTALLER)
    if(TRINTRIN_PYTHON_PIP_METADATA_INSTALL)
      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/METADATA "")
      file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/METADATA "Metadata-Version: 2.1${NEW_LINE}")
      file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/METADATA "Name: trintrin${NEW_LINE}")
      file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/METADATA "Version: ${trintrin_VERSION}${NEW_LINE}")
      file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/INSTALLER "${TRINTRIN_PYTHON_PIP_METADATA_INSTALLER}${NEW_LINE}")
      install(
        FILES "${CMAKE_CURRENT_BINARY_DIR}/METADATA" "${CMAKE_CURRENT_BINARY_DIR}/INSTALLER"
        DESTINATION ${TRINTRIN_PYTHON_INSTALL_DIR}/trintrin-${trintrin_VERSION}.dist-info)
    endif()

endif()
