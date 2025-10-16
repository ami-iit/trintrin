// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <trintrin/msgs/VectorXYZ.h>
#include <trintrin/msgs/VectorRPY.h>
#include <trintrin/msgs/Quaternion.h>
#include <trintrin/msgs/Transform.h>

#include <trintrin/bindings/msgs/BufferedPort.h>
#include <trintrin/bindings/msgs/Common.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateVectorXYZ(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::VectorXYZ>(module, "VectorXYZ")
                    .def(py::init())
                    .def_readwrite("x", &::trintrin::msgs::VectorXYZ::x)
                    .def_readwrite("y", &::trintrin::msgs::VectorXYZ::y)
                    .def_readwrite("z", &::trintrin::msgs::VectorXYZ::z)
                    .def("__str__", &::trintrin::msgs::VectorXYZ::toString)
                    .def("toString", &::trintrin::msgs::VectorXYZ::toString);
                CreateBufferedPort<::trintrin::msgs::VectorXYZ>(module, "BufferedPortVectorXYZ");
            }

            void CreateVectorRPY(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::VectorRPY>(module, "VectorRPY")
                    .def(py::init())
                    .def_readwrite("roll", &::trintrin::msgs::VectorRPY::r)
                    .def_readwrite("pitch", &::trintrin::msgs::VectorRPY::p)
                    .def_readwrite("yaw", &::trintrin::msgs::VectorRPY::y)
                    .def("__str__", &::trintrin::msgs::VectorRPY::toString)
                    .def("toString", &::trintrin::msgs::VectorRPY::toString);
                CreateBufferedPort<::trintrin::msgs::VectorRPY>(module, "BufferedPortVectorRPY");
            }

            void CreateQuaternion(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::Quaternion>(module, "Quaternion")
                    .def(py::init())
                    .def_readwrite("w", &::trintrin::msgs::Quaternion::w)
                    .def_readwrite("imaginary", &::trintrin::msgs::Quaternion::imaginary)
                    .def("__str__", &::trintrin::msgs::Quaternion::toString)
                    .def("toString", &::trintrin::msgs::Quaternion::toString);
                CreateBufferedPort<::trintrin::msgs::Quaternion>(module, "BufferedPortQuaternion");
            }

            void CreateTransform(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::Transform>(module, "Transform")
                    .def(py::init())
                    .def_readwrite("position", &::trintrin::msgs::Transform::position)
                    .def_readwrite("orientation", &::trintrin::msgs::Transform::orientation)
                    .def("__str__", &::trintrin::msgs::Transform::toString)
                    .def("toString", &::trintrin::msgs::Transform::toString);
                CreateBufferedPort<::trintrin::msgs::Transform>(module, "BufferedPortTransform");
            }

            void CreateCommon(pybind11::module& module)
            {
                namespace py = ::pybind11;
                CreateVectorXYZ(module);
                CreateVectorRPY(module);
                CreateQuaternion(module);
                CreateTransform(module);

            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin
