// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

include "Common.thrift"

namespace yarp trintrin.msgs

struct HumanState {
    1: list<string> jointNames;
    2: list<double> positions;
    3: list<double> velocities;

    4: string baseName;
    5: Common.VectorXYZ baseOriginWRTGlobal;
    6: Common.Quaternion baseOrientationWRTGlobal;
    7: list<double> baseVelocityWRTGlobal;
    8: Common.VectorXYZ CoMPositionWRTGlobal;
    9: Common.VectorXYZ CoMVelocityWRTGlobal;
}
