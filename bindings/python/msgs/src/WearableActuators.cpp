// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <trintrin/msgs/ActuatorType.h>
#include <trintrin/msgs/ActuatorInfo.h>
#include <trintrin/msgs/WearableActuatorCommand.h>
#include <trintrin/msgs/GloveActuatorCommand.h>

#include <trintrin/bindings/msgs/BufferedPort.h>
#include <trintrin/bindings/msgs/WearableActuators.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateActuatorType(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::enum_<::trintrin::msgs::ActuatorType>(module, "ActuatorType")
                    .value("HAPTIC", ::trintrin::msgs::HAPTIC)
                    .value("MOTOR", ::trintrin::msgs::MOTOR)
                    .value("HEATER", ::trintrin::msgs::HEATER)
                    .export_values();
            }

            void CreateActuatorInfo(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::ActuatorInfo>(module, "ActuatorInfo")
                    .def(py::init())
                    .def_readwrite("name", &::trintrin::msgs::ActuatorInfo::name)
                    .def_readwrite("type", &::trintrin::msgs::ActuatorInfo::type)
                    .def("__str__", &::trintrin::msgs::ActuatorInfo::toString)
                    .def("toString", &::trintrin::msgs::ActuatorInfo::toString);

                CreateBufferedPort<::trintrin::msgs::ActuatorInfo>(module, "BufferedActuatorInfo");
            }

            void CreateWearableActuatorCommand(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::WearableActuatorCommand>(module, "WearableActuatorCommand")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::WearableActuatorCommand::info)
                    .def_readwrite("value", &::trintrin::msgs::WearableActuatorCommand::value)
                    .def_readwrite("duration", &::trintrin::msgs::WearableActuatorCommand::duration)
                    .def("__str__", &::trintrin::msgs::WearableActuatorCommand::toString)
                    .def("toString", &::trintrin::msgs::WearableActuatorCommand::toString);
                CreateBufferedPort<::trintrin::msgs::WearableActuatorCommand>(
                    module, "BufferedPortWearableActuatorCommand");
            }

            void CreateGloveActuatorCommand(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::GloveActuatorCommand>(module, "GloveActuatorCommand")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::GloveActuatorCommand::info)
                    .def_readwrite("forceValue", &::trintrin::msgs::GloveActuatorCommand::forceValue)
                    .def_readwrite("vibroTactileValue", &::trintrin::msgs::GloveActuatorCommand::vibroTactileValue)
                    .def("__str__", &::trintrin::msgs::GloveActuatorCommand::toString)
                    .def("toString", &::trintrin::msgs::GloveActuatorCommand::toString);
                CreateBufferedPort<::trintrin::msgs::GloveActuatorCommand>(
                    module, "BufferedPortGloveActuatorCommand");
            }

            void CreateWearableActuators(pybind11::module& module)
            {
                CreateActuatorType(module);
                CreateActuatorInfo(module);
                CreateWearableActuatorCommand(module);
                CreateGloveActuatorCommand(module);
            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin
