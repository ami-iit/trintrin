// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

namespace yarp trintrin.msgs

struct HumanDynamics {
    1: list<string> jointNames;
    2: list<double> torques;
}
