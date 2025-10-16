// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#include <pybind11/pybind11.h>

#include <trintrin/bindings/msgs/Common.h>
#include <trintrin/bindings/msgs/HumanDynamics.h>
#include <trintrin/bindings/msgs/HumanState.h>
#include <trintrin/bindings/msgs/HumanWrench.h>
#include <trintrin/bindings/msgs/WearableActuators.h>
#include <trintrin/bindings/msgs/WearableData.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateModule(pybind11::module& module)
            {
                module.doc() = "trintrin messages module.";

                CreateCommon(module);
                CreateHumanDynamics(module);
                CreateHumanState(module);
                CreateHumanWrench(module);
                CreateWearableActuators(module);
                CreateWearableData(module);
            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin
