# SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause


set(H_PREFIX include/trintrin/bindings/msgs)

set(TRINTRIN_BINDINGS_MSGS_SRC
    src/Common.cpp
    src/HumanDynamics.cpp
    src/HumanState.cpp
    src/HumanWrench.cpp
    src/WearableActuators.cpp
    src/WearableData.cpp
    src/WearableTargets.cpp
    src/Module.cpp
)

set(TRINTRIN_BINDINGS_MSGS_HDR
    ${H_PREFIX}/Common.h
    ${H_PREFIX}/HumanDynamics.h
    ${H_PREFIX}/HumanState.h
    ${H_PREFIX}/HumanWrench.h
    ${H_PREFIX}/WearableActuators.h
    ${H_PREFIX}/WearableData.h
    ${H_PREFIX}/WearableTargets.h
    ${H_PREFIX}/BufferedPort.h
    ${H_PREFIX}/Module.h
)

add_trintrin_python_module(
    NAME TrintrinMsgsBindings
    SOURCES ${TRINTRIN_BINDINGS_MSGS_SRC}
    HEADERS ${TRINTRIN_BINDINGS_MSGS_HDR}
    LINK_LIBRARIES trintrin::msgs YARP::YARP_os
    TESTS tests/test_load.py)
