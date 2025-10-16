// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <trintrin/msgs/HumanWrench.h>

#include <trintrin/bindings/msgs/BufferedPort.h>
#include <trintrin/bindings/msgs/HumanWrench.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateHumanWrench(pybind11::module& module)
            {
                namespace py = ::pybind11;
                using namespace ::trintrin::msgs;

                py::class_<HumanWrench>(module, "HumanWrench")
                    .def(py::init())
                    .def_readwrite("wrenchSourceNames", &HumanWrench::wrenchSourceNames)
                    .def_readwrite("wrenches", &HumanWrench::wrenches)
                    .def("__str__", &HumanWrench::toString)
                    .def("toString", &HumanWrench::toString);

                CreateBufferedPort<HumanWrench>(module, "BufferedPortHumanWrench");
            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin
