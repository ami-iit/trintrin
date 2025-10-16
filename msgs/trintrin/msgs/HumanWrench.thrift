// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

namespace yarp trintrin.msgs

/**
 * Representation of the IHumanWrench interface
 */
struct HumanWrench {
    1: list<string> wrenchSourceNames;
    2: list<double> wrenches;
}
