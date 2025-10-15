# SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

yarp_add_idl(Common_FILES Common.thrift)
yarp_add_idl(HumanDynamics_FILES HumanDynamics.thrift)
yarp_add_idl(HumanState_FILES HumanState.thrift)
yarp_add_idl(HumanWrench_FILES HumanWrench.thrift)
yarp_add_idl(WearableActuators_FILES WearableActuators.thrift)
yarp_add_idl(WearableData_FILES WearableData.thrift)
yarp_add_idl(WearableTargets_FILES WearableTargets.thrift)


add_library(trintrin_msgs
            ${Common_FILES}
            ${HumanDynamics_FILES}
            ${HumanState_FILES}
            ${HumanWrench_FILES}
            ${WearableActuators_FILES}
            ${WearableData_FILES}
            ${WearableTargets_FILES})

add_library(trintrin::msgs ALIAS trintrin_msgs)
target_link_libraries(trintrin_msgs YARP::YARP_os)

install(TARGETS trintrin_msgs
        EXPORT trintrin
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

