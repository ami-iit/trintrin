// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause


#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <trintrin/msgs/WearableData.h>

#include <trintrin/bindings/msgs/BufferedPort.h>
#include <trintrin/bindings/msgs/WearableData.h>

namespace trintrin {
    namespace bindings {
        namespace msgs {

            void CreateSensorStatus(pybind11::module& module)
            {
                namespace py = ::pybind11;

                py::enum_<::trintrin::msgs::SensorStatus>(module, "SensorStatus")
                    .value("ERROR", ::trintrin::msgs::ERROR)
                    .value("OK", ::trintrin::msgs::OK)
                    .value("CALIBRATING", ::trintrin::msgs::CALIBRATING)
                    .value("DATA_OVERFLOW", ::trintrin::msgs::DATA_OVERFLOW)
                    .value("TIMEOUT", ::trintrin::msgs::TIMEOUT)
                    .value("UNKNOWN", ::trintrin::msgs::UNKNOWN)
                    .value("WAITING_FOR_FIRST_READ", ::trintrin::msgs::WAITING_FOR_FIRST_READ)
                    .export_values();
            }

            void CreateSensorInfo(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::SensorInfo>(module, "SensorInfo")
                                        .def(py::init())
                    .def_readwrite("name", &::trintrin::msgs::SensorInfo::name)
                    .def_readwrite("status", &::trintrin::msgs::SensorInfo::status)
                    .def("__str__", &::trintrin::msgs::SensorInfo::toString)
                    .def("toString", &::trintrin::msgs::SensorInfo::toString);

                CreateBufferedPort<::trintrin::msgs::SensorInfo>(module, "BufferedPortSensorInfo");
            }

            void CreateForceTorque6DSensorData(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::ForceTorque6DSensorData>(module,
                    "ForceTorque6DSensorData")
                    .def(py::init())
                    .def_readwrite("force", &::trintrin::msgs::ForceTorque6DSensorData::force)
                    .def_readwrite("torque", &::trintrin::msgs::ForceTorque6DSensorData::torque)
                    .def("__str__", &::trintrin::msgs::ForceTorque6DSensorData::toString)
                    .def("toString", &::trintrin::msgs::ForceTorque6DSensorData::toString);

                CreateBufferedPort<::trintrin::msgs::ForceTorque6DSensorData>(
                    module, "BufferedPortForceTorque6DSensorData");
            }

            void CreatePoseSensorData(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::PoseSensorData>(module, "PoseSensorData")
                    .def(py::init())
                    .def_readwrite("orientation", &::trintrin::msgs::PoseSensorData::orientation)
                    .def_readwrite("position", &::trintrin::msgs::PoseSensorData::position)
                    .def("__str__", &::trintrin::msgs::PoseSensorData::toString)
                    .def("toString", &::trintrin::msgs::PoseSensorData::toString);
                CreateBufferedPort<::trintrin::msgs::PoseSensorData>(module, "BufferedPortPoseSensorData");
            }

            void CreateVirtualLinkKinSensorData(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::VirtualLinkKinSensorData>(module,
                    "VirtualLinkKinSensorData")
                    .def(py::init())
                    .def_readwrite("orientation",
                        &::trintrin::msgs::VirtualLinkKinSensorData::orientation)
                    .def_readwrite("position", &::trintrin::msgs::VirtualLinkKinSensorData::position)
                    .def_readwrite("linearVelocity",
                        &::trintrin::msgs::VirtualLinkKinSensorData::linearVelocity)
                    .def_readwrite("angularVelocity",
                        &::trintrin::msgs::VirtualLinkKinSensorData::angularVelocity)
                    .def_readwrite("linearAcceleration",
                        &::trintrin::msgs::VirtualLinkKinSensorData::linearAcceleration)
                    .def_readwrite("angularAcceleration",
                        &::trintrin::msgs::VirtualLinkKinSensorData::angularAcceleration)
                    .def("__str__", &::trintrin::msgs::VirtualLinkKinSensorData::toString)
                    .def("toString", &::trintrin::msgs::VirtualLinkKinSensorData::toString);
                CreateBufferedPort<::trintrin::msgs::VirtualLinkKinSensorData>(
                    module, "BufferedPortVirtualLinkKinSensorData");
            }

            void CreateVirtualJointKinSensorData(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::VirtualJointKinSensorData>(module,
                    "VirtualJointKinSensorData")
                    .def(py::init())
                    .def_readwrite("position", &::trintrin::msgs::VirtualJointKinSensorData::position)
                    .def_readwrite("velocity", &::trintrin::msgs::VirtualJointKinSensorData::velocity)
                    .def_readwrite("acceleration",
                        &::trintrin::msgs::VirtualJointKinSensorData::acceleration)
                    .def("__str__", &::trintrin::msgs::VirtualJointKinSensorData::toString)
                    .def("toString", &::trintrin::msgs::VirtualJointKinSensorData::toString);

                CreateBufferedPort<::trintrin::msgs::VirtualJointKinSensorData>(
                    module, "BufferedPortVirtualJointKinSensorData");
            }

            void CreateVirtualSphericalJointKinSensorData(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::VirtualSphericalJointKinSensorData>(module,
                    "VirtualSphericalJointKinSensorData")
                    .def(py::init())
                    .def_readwrite("angle", &::trintrin::msgs::VirtualSphericalJointKinSensorData::angle)
                    .def_readwrite("velocity",
                        &::trintrin::msgs::VirtualSphericalJointKinSensorData::velocity)
                    .def_readwrite("acceleration",
                        &::trintrin::msgs::VirtualSphericalJointKinSensorData::acceleration)
                    .def("__str__", &::trintrin::msgs::VirtualSphericalJointKinSensorData::toString)
                    .def("toString", &::trintrin::msgs::VirtualSphericalJointKinSensorData::toString);

                CreateBufferedPort<::trintrin::msgs::VirtualSphericalJointKinSensorData>(
                    module, "BufferedPortVirtualSphericalJointKinSensorData");
            }

            void CreateEmgData(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::EmgData>(module, "EmgData")
                    .def(py::init())
                    .def_readwrite("value", &::trintrin::msgs::EmgData::value)
                    .def_readwrite("normalization", &::trintrin::msgs::EmgData::normalization)
                    .def("__str__", &::trintrin::msgs::EmgData::toString)
                    .def("toString", &::trintrin::msgs::EmgData::toString);

                CreateBufferedPort<::trintrin::msgs::EmgData>(module, "BufferedPortEmgData");
            }

            void CreateAccelerometer(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::Accelerometer>(module, "Accelerometer")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::Accelerometer::info)
                    .def_readwrite("data", &::trintrin::msgs::Accelerometer::data)
                    .def("__str__", &::trintrin::msgs::Accelerometer::toString)
                    .def("toString", &::trintrin::msgs::Accelerometer::toString);

                CreateBufferedPort<::trintrin::msgs::Accelerometer>(module, "BufferedPortAccelerometer");
            }

            void CreateEmgSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::EmgSensor>(module, "EmgSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::EmgSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::EmgSensor::data)
                    .def("__str__", &::trintrin::msgs::EmgSensor::toString)
                    .def("toString", &::trintrin::msgs::EmgSensor::toString);

                CreateBufferedPort<::trintrin::msgs::EmgSensor>(module, "BufferedPortEmgSensor");
            }

            void CreateFreeBodyAccelerationSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::FreeBodyAccelerationSensor>(module,
                    "FreeBodyAccelerationSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::FreeBodyAccelerationSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::FreeBodyAccelerationSensor::data)
                    .def("__str__", &::trintrin::msgs::FreeBodyAccelerationSensor::toString)
                    .def("toString", &::trintrin::msgs::FreeBodyAccelerationSensor::toString);

                CreateBufferedPort<::trintrin::msgs::FreeBodyAccelerationSensor>(
                    module, "BufferedPortFreeBodyAccelerationSensor");
            }

            void CreateForce3DSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::Force3DSensor>(module, "Force3DSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::Force3DSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::Force3DSensor::data)
                    .def("__str__", &::trintrin::msgs::Force3DSensor::toString)
                    .def("toString", &::trintrin::msgs::Force3DSensor::toString);

                CreateBufferedPort<::trintrin::msgs::Force3DSensor>(module, "BufferedPortForce3DSensor");
            }

            void CreateForceTorque6DSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::ForceTorque6DSensor>(module, "ForceTorque6DSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::ForceTorque6DSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::ForceTorque6DSensor::data)
                    .def("__str__", &::trintrin::msgs::ForceTorque6DSensor::toString)
                    .def("toString", &::trintrin::msgs::ForceTorque6DSensor::toString);

                CreateBufferedPort<::trintrin::msgs::ForceTorque6DSensor>(
                    module, "BufferedPortForceTorque6DSensor");
            }

            void CreateGyroscope(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::Gyroscope>(module, "Gyroscope")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::Gyroscope::info)
                    .def_readwrite("data", &::trintrin::msgs::Gyroscope::data)
                    .def("__str__", &::trintrin::msgs::Gyroscope::toString)
                    .def("toString", &::trintrin::msgs::Gyroscope::toString);

                CreateBufferedPort<::trintrin::msgs::Gyroscope>(module, "BufferedPortGyroscope");
            }

            void CreateMagnetometer(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::Magnetometer>(module, "Magnetometer")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::Magnetometer::info)
                    .def_readwrite("data", &::trintrin::msgs::Magnetometer::data)
                    .def("__str__", &::trintrin::msgs::Magnetometer::toString)
                    .def("toString", &::trintrin::msgs::Magnetometer::toString);

                CreateBufferedPort<::trintrin::msgs::Magnetometer>(module, "BufferedPortMagnetometer");
            }

            void CreateOrientationSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::OrientationSensor>(module, "OrientationSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::OrientationSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::OrientationSensor::data)
                    .def("__str__", &::trintrin::msgs::OrientationSensor::toString)
                    .def("toString", &::trintrin::msgs::OrientationSensor::toString);

                CreateBufferedPort<::trintrin::msgs::OrientationSensor>(
                    module, "BufferedPortOrientationSensor");
            }

            void CreatePoseSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::PoseSensor>(module, "PoseSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::PoseSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::PoseSensor::data)
                    .def("__str__", &::trintrin::msgs::PoseSensor::toString)
                    .def("toString", &::trintrin::msgs::PoseSensor::toString);

                CreateBufferedPort<::trintrin::msgs::PoseSensor>(module, "BufferedPortPoseSensor");
            }

            void CreatePositionSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::PositionSensor>(module, "PositionSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::PositionSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::PositionSensor::data)
                    .def("__str__", &::trintrin::msgs::PositionSensor::toString)
                    .def("toString", &::trintrin::msgs::PositionSensor::toString);

                CreateBufferedPort<::trintrin::msgs::PositionSensor>(module, "BufferedPortPositionSensor");
            }

            void CreateSkinSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::SkinSensor>(module, "SkinSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::SkinSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::SkinSensor::data)
                    .def("__str__", &::trintrin::msgs::SkinSensor::toString)
                    .def("toString", &::trintrin::msgs::SkinSensor::toString);

                CreateBufferedPort<::trintrin::msgs::SkinSensor>(module, "BufferedPortSkinSensor");
            }

            void CreateTemperatureSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::TemperatureSensor>(module, "TemperatureSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::TemperatureSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::TemperatureSensor::data)
                    .def("__str__", &::trintrin::msgs::TemperatureSensor::toString)
                    .def("toString", &::trintrin::msgs::TemperatureSensor::toString);

                CreateBufferedPort<::trintrin::msgs::TemperatureSensor>(
                    module, "BufferedPortTemperatureSensor");
            }

            void CreateTorque3DSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::Torque3DSensor>(module, "Torque3DSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::Torque3DSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::Torque3DSensor::data)
                    .def("__str__", &::trintrin::msgs::Torque3DSensor::toString)
                    .def("toString", &::trintrin::msgs::Torque3DSensor::toString);

                CreateBufferedPort<::trintrin::msgs::Torque3DSensor>(module, "BufferedPortTorque3DSensor");
            }

            void CreateVirtualLinkKinSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::VirtualLinkKinSensor>(module, "VirtualLinkKinSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::VirtualLinkKinSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::VirtualLinkKinSensor::data)
                    .def("__str__", &::trintrin::msgs::VirtualLinkKinSensor::toString)
                    .def("toString", &::trintrin::msgs::VirtualLinkKinSensor::toString);

                CreateBufferedPort<::trintrin::msgs::VirtualLinkKinSensor>(
                    module, "BufferedPortVirtualLinkKinSensor");
            }

            void CreateVirtualJointKinSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::VirtualJointKinSensor>(module, "VirtualJointKinSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::VirtualJointKinSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::VirtualJointKinSensor::data)
                    .def("__str__", &::trintrin::msgs::VirtualJointKinSensor::toString)
                    .def("toString", &::trintrin::msgs::VirtualJointKinSensor::toString);

                CreateBufferedPort<::trintrin::msgs::VirtualJointKinSensor>(
                    module, "BufferedPortVirtualJointKinSensor");
            }

            void CreateVirtualSphericalJointKinSensor(pybind11::module& module)
            {
                namespace py = ::pybind11;
                py::class_<::trintrin::msgs::VirtualSphericalJointKinSensor>(
                    module, "VirtualSphericalJointKinSensor")
                    .def(py::init())
                    .def_readwrite("info", &::trintrin::msgs::VirtualSphericalJointKinSensor::info)
                    .def_readwrite("data", &::trintrin::msgs::VirtualSphericalJointKinSensor::data)
                    .def("__str__", &::trintrin::msgs::VirtualSphericalJointKinSensor::toString)
                    .def("toString", &::trintrin::msgs::VirtualSphericalJointKinSensor::toString);

                CreateBufferedPort<::trintrin::msgs::VirtualSphericalJointKinSensor>(
                    module, "BufferedPortVirtualSphericalJointKinSensor");
            }


            void CreateWearableData(pybind11::module& module)
            {
                namespace py = ::pybind11;

                CreateSensorStatus(module);
                CreateSensorInfo(module);
                CreateForceTorque6DSensorData(module);
                CreatePoseSensorData(module);
                CreateVirtualLinkKinSensorData(module);
                CreateVirtualJointKinSensorData(module);
                CreateVirtualSphericalJointKinSensorData(module);
                CreateEmgData(module);
                CreateAccelerometer(module);
                CreateEmgSensor(module);
                CreateFreeBodyAccelerationSensor(module);
                CreateForce3DSensor(module);
                CreateForceTorque6DSensor(module);
                CreateGyroscope(module);
                CreateMagnetometer(module);
                CreateOrientationSensor(module);
                CreatePoseSensor(module);
                CreatePositionSensor(module);
                CreateSkinSensor(module);
                CreateTemperatureSensor(module);
                CreateTorque3DSensor(module);
                CreateVirtualLinkKinSensor(module);
                CreateVirtualJointKinSensor(module);
                CreateVirtualSphericalJointKinSensor(module);


                py::class_<::trintrin::msgs::WearableData>(module, "WearableData")
                    .def(py::init())
                    .def_readwrite("producerName", &::trintrin::msgs::WearableData::producerName)
                    .def_readwrite("accelerometers", &::trintrin::msgs::WearableData::accelerometers)
                    .def_readwrite("emgSensors", &::trintrin::msgs::WearableData::emgSensors)
                    .def_readwrite("force3DSensors", &::trintrin::msgs::WearableData::force3DSensors)
                    .def_readwrite("forceTorque6DSensors", &::trintrin::msgs::WearableData::forceTorque6DSensors)
                    .def_readwrite("freeBodyAccelerationSensors", &::trintrin::msgs::WearableData::freeBodyAccelerationSensors)
                    .def_readwrite("gyroscopes", &::trintrin::msgs::WearableData::gyroscopes)
                    .def_readwrite("magnetometers", &::trintrin::msgs::WearableData::magnetometers)
                    .def_readwrite("orientationSensors", &::trintrin::msgs::WearableData::orientationSensors)
                    .def_readwrite("poseSensors", &::trintrin::msgs::WearableData::poseSensors)
                    .def_readwrite("positionSensors", &::trintrin::msgs::WearableData::positionSensors)
                    .def_readwrite("skinSensors", &::trintrin::msgs::WearableData::skinSensors)
                    .def_readwrite("temperatureSensors", &::trintrin::msgs::WearableData::temperatureSensors)
                    .def_readwrite("torque3DSensors", &::trintrin::msgs::WearableData::torque3DSensors)
                    .def_readwrite("virtualLinkKinSensors", &::trintrin::msgs::WearableData::virtualLinkKinSensors)
                    .def_readwrite("virtualJointKinSensors", &::trintrin::msgs::WearableData::virtualJointKinSensors)
                    .def_readwrite("virtualSphericalJointKinSensors", &::trintrin::msgs::WearableData::virtualSphericalJointKinSensors)
                    .def("__str__", &::trintrin::msgs::WearableData::toString)
                    .def("toString", &::trintrin::msgs::WearableData::toString);

                CreateBufferedPort<::trintrin::msgs::WearableData>(module, "BufferedPortWearableData");
            }
        } // namespace msgs
    } // namespace bindings
} // namespace trintrin
