// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <trintrin/msgs/HumanDynamics.h>

#include <trintrin/bindings/msgs/BufferedPort.h>
#include <trintrin/bindings/msgs/HumanDynamics.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateHumanDynamics(pybind11::module& module)
            {
                namespace py = ::pybind11;
                using namespace ::trintrin::msgs;

                py::class_<HumanDynamics>(module, "HumanDynamics")
                    .def(py::init())
                    .def_readwrite("jointNames", &HumanDynamics::jointNames)
                    .def_readwrite("torques", &HumanDynamics::torques)
                    .def("__str__", &HumanDynamics::toString)
                    .def("toString", &HumanDynamics::toString);

                CreateBufferedPort<HumanDynamics>(module, "BufferedPortHumanDynamics");
            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin
