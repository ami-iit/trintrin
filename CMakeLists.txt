# SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(trintrin
        LANGUAGES CXX
        VERSION 0.0.1)

# =====================
# PROJECT CONFIGURATION
# =====================

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
include(CTest)

# Find packages needed for this main CMakeLists.txt.
# Subfolders will find the dependencies they need.
find_package(YARP 3.2 REQUIRED)
find_package(YCM REQUIRED)

# To build shared libraries in Windows, we set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to TRUE
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Shared/Dynamic or Static library?
option(BUILD_SHARED_LIBS "Build libraries as shared as opposed to static" ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Flag to enable python bindings
option(TRIN_COMPILE_PYTHON_BINDINGS "Flag that enables building the bindings" OFF)

# Control where binaries and libraries are placed in the build folder.
# This simplifies tests running in Windows.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")

# Enable RPATH support for installed binaries and libraries
include(AddInstallRPATHSupport)
add_install_rpath_support(BIN_DIRS "${CMAKE_INSTALL_FULL_BINDIR}"
                          LIB_DIRS "${CMAKE_INSTALL_FULL_LIBDIR}"
                          INSTALL_NAME_DIR "${CMAKE_INSTALL_FULL_LIBDIR}"
                          USE_LINK_PATH)


# Add the uninstall target
include(AddUninstallTarget)

# ===================
# PROJECT DIRECTORIES
# ===================
include(InstallBasicPackageFiles)

add_subdirectory(msgs)

install_basic_package_files(${PROJECT_NAME}
  VERSION ${${PROJECT_NAME}_VERSION}
  COMPATIBILITY AnyNewerVersion
  VARS_PREFIX ${PROJECT_NAME}
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  DEPENDENCIES YARP)

# Add the uninstall target
include(AddUninstallTarget)
