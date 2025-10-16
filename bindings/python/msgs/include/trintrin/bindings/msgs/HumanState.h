// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#ifndef TRINTRIN_BINDINGS_MSGS_HUMAN_STATE_H
#define TRINTRIN_BINDINGS_MSGS_HUMAN_STATE_H

#include <pybind11/pybind11.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateHumanState(pybind11::module& module);

        } // namespace msgs
    } // namespace bindings
} // namespace trintrin

#endif // TRINTRIN_BINDINGS_MSGS_HUMAN_STATE_H