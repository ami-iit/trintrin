// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

namespace yarp trintrin.msgs

struct VectorXYZ {
  1: double x;
  2: double y;
  3: double z;
}

struct VectorRPY {
  1: double r;
  2: double p;
  3: double y;
}

struct Quaternion {
    1: double w;
    2: VectorXYZ imaginary;
}

struct Transform {
    1: VectorXYZ position
    2: Quaternion orientation
}
