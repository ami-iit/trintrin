# SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

function(add_trintrin_python_module)

  set(options )
  set(oneValueArgs NAME)
  set(multiValueArgs
    SOURCES
    HEADERS
    LINK_LIBRARIES
    TESTS
    TESTS_RUNTIME_CONDITIONS)

  set(prefix "trintrin")

  cmake_parse_arguments(${prefix}
    "${options}"
    "${oneValueArgs}"
    "${multiValueArgs}"
    ${ARGN})

  set(name ${${prefix}_NAME})
  set(is_interface ${${prefix}_IS_INTERFACE})
  set(sources ${${prefix}_SOURCES})
  set(headers ${${prefix}_HEADERS})
  set(link_libraries ${${prefix}_LINK_LIBRARIES})
  set(subdirectories ${${prefix}_SUBDIRECTORIES})
  set(tests ${${prefix}_TESTS})
  set(tests_runtime_conditions ${${prefix}_TESTS_RUNTIME_CONDITIONS})

  foreach(file ${headers})
    set_property(GLOBAL APPEND PROPERTY pybind_headers ${CMAKE_CURRENT_SOURCE_DIR}/${file})
  endforeach()

  foreach(file ${sources})
    set_property(GLOBAL APPEND PROPERTY pybind_sources ${CMAKE_CURRENT_SOURCE_DIR}/${file})
  endforeach()

  set_property(GLOBAL APPEND PROPERTY pybind_include_dirs ${CMAKE_CURRENT_SOURCE_DIR}/include)

  set_property(GLOBAL APPEND PROPERTY pybind_link_libraries ${link_libraries})

  message(STATUS "Added files for bindings named ${name} in ${PROJECT_NAME}.")

endfunction()

add_subdirectory(msgs)

get_property(pybind_headers GLOBAL PROPERTY pybind_headers)
get_property(pybind_sources GLOBAL PROPERTY pybind_sources)
get_property(pybind_include_dirs GLOBAL PROPERTY pybind_include_dirs)
get_property(pybind_link_libraries GLOBAL PROPERTY pybind_link_libraries)

pybind11_add_module(pybind11_trintrin MODULE
  trintrin.cpp
  ${pybind_sources}
  ${pybind_headers}
  )

target_include_directories(pybind11_trintrin PUBLIC "$<BUILD_INTERFACE:${pybind_include_dirs}>")

target_link_libraries(pybind11_trintrin PRIVATE
  ${pybind_link_libraries})

# # The generated Python dynamic module must have the same name as the pybind11
# # module, i.e. `bindings`.
set_target_properties(pybind11_trintrin PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY "${TRINTRIN_PYTHON_PACKAGE}"
  ARCHIVE_OUTPUT_DIRECTORY "${TRINTRIN_PYTHON_PACKAGE}"
  RUNTIME_OUTPUT_DIRECTORY "${TRINTRIN_PYTHON_PACKAGE}"
  PDB_OUTPUT_DIRECTORY "${TRINTRIN_PYTHON_PACKAGE}"
  OUTPUT_NAME "bindings")

# Output package is:
#
# trintrin
# |-- __init__.py (generated from main bindings CMake file)
# `-- bindings.<cpython_extension>

install(TARGETS pybind11_trintrin DESTINATION ${PYTHON_INSTDIR})
