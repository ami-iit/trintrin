# SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

get_property(bindings_tests GLOBAL PROPERTY TrinTrinBindings_TESTS)

add_test(NAME PythonBindingsUnitTest
    COMMAND ${Python3_EXECUTABLE} -m pytest ${bindings_tests}
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)
