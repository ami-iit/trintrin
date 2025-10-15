// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

include "Common.thrift"

namespace yarp trintrin.msgs

enum KinematicTargetType {
    NONE,
    POSE,
    POSEANDVELOCITY,
    POSITION,
    POSITIONANDVELOCITY,
    ORIENTATION,
    ORIENTATIONANDVELOCITY,
    GRAVITY,
    FLOORCONTACT
}

struct WearableTarget {
    1: string wearableSensorName;
    2: string linkName;
    3: KinematicTargetType type;
    4: Common.VectorXYZ position;
    5: Common.Quaternion orientation;
    6: Common.VectorXYZ linearVelocity;
    7: Common.VectorXYZ angularVelocity;
    8: Common.Transform calibrationWorldToMeasurementWorld;
    9: Common.Transform calibrationMeasurementToLink;
    10: Common.VectorXYZ positionScaleFactor;
}

struct WearableTargets {
    1: map<string,WearableTarget> targets;
}
