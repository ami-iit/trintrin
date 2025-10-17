// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#ifndef TRINTRIN_BINDINGS_MSGS_WEARABLE_TARGETS_H
#define TRINTRIN_BINDINGS_MSGS_WEARABLE_TARGETS_H

#include <pybind11/pybind11.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateWearableTargets(pybind11::module& module);

        } // namespace msgs
    } // namespace bindings
} // namespace trintrin

#endif // TRINTRIN_BINDINGS_MSGS_WEARABLE_TARGETS_H
