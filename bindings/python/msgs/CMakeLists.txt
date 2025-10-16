# SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause


set(H_PREFIX include/trintrin/bindings/msgs)

add_trintrin_python_module(
    NAME MsgsBindings
    SOURCES src/Common.cpp src/HumanState.cpp src/WearableData.cpp src/Module.cpp
    HEADERS ${H_PREFIX}/Common.h ${H_PREFIX}/HumanState.h ${H_PREFIX}/WearableData.h ${H_PREFIX}/BufferedPort.h ${H_PREFIX}/Module.h
    LINK_LIBRARIES trintrin::msgs YARP::YARP_os)
