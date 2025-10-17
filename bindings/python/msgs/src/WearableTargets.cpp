// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <trintrin/msgs/WearableTargets.h>

#include <trintrin/bindings/msgs/BufferedPort.h>
#include <trintrin/bindings/msgs/WearableTargets.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateKinematicTargetType(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::enum_<::trintrin::msgs::KinematicTargetType>(module, "KinematicTargetType")
                    .value("NONE", ::trintrin::msgs::NONE)
                    .value("POSE", ::trintrin::msgs::POSE)
                    .value("POSEANDVELOCITY", ::trintrin::msgs::POSEANDVELOCITY)
                    .value("POSITION", ::trintrin::msgs::POSITION)
                    .value("POSITIONANDVELOCITY", ::trintrin::msgs::POSITIONANDVELOCITY)
                    .value("ORIENTATION", ::trintrin::msgs::ORIENTATION)
                    .value("ORIENTATIONANDVELOCITY", ::trintrin::msgs::ORIENTATIONANDVELOCITY)
                    .value("GRAVITY", ::trintrin::msgs::GRAVITY)
                    .value("FLOORCONTACT", ::trintrin::msgs::FLOORCONTACT)
                    .export_values();
            }

            void CreateWearableTarget(pybind11::module& module)
            {
                namespace py = ::pybind11;
                using namespace ::trintrin::msgs;
                py::class_<WearableTarget>(module, "WearableTarget")
                    .def(py::init())
                    .def_readwrite("wearableSensorName", &WearableTarget::wearableSensorName)
                    .def_readwrite("linkName", &WearableTarget::linkName)
                    .def_readwrite("type", &WearableTarget::type)
                    .def_readwrite("position", &WearableTarget::position)
                    .def_readwrite("orientation", &WearableTarget::orientation)
                    .def_readwrite("linearVelocity", &WearableTarget::linearVelocity)
                    .def_readwrite("angularVelocity", &WearableTarget::angularVelocity)
                    .def_readwrite("calibrationWorldToMeasurementWorld", &WearableTarget::calibrationWorldToMeasurementWorld)
                    .def_readwrite("calibrationMeasurementToLink", &WearableTarget::calibrationMeasurementToLink)
                    .def_readwrite("positionScaleFactor", &WearableTarget::positionScaleFactor)
                    .def("__str__", &WearableTarget::toString)
                    .def("toString", &WearableTarget::toString);
            }

            void CreateWearableTargets(pybind11::module& module)
            {
                namespace py = ::pybind11;
                using namespace ::trintrin::msgs;

                CreateKinematicTargetType(module);
                CreateWearableTarget(module);

                py::class_<WearableTargets>(module, "WearableTargets")
                    .def(py::init())
                    .def_readwrite("targets", &WearableTargets::targets)
                    .def("__str__", &WearableTargets::toString)
                    .def("toString", &WearableTargets::toString);

                CreateBufferedPort<WearableTargets>(module, "BufferedPortWearableTargets");
            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin
