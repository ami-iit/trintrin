// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#include <pybind11/pybind11.h>

#include <trintrin/bindings/msgs/HumanState.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateModule(pybind11::module& module)
            {
                module.doc() = "trintrin messages module.";

                CreateHumanState(module);
            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin