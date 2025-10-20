# trintrin

Set of messages and interfaces used in Artificial Mechanical Intelligence.

## Installation  

### robotology-superbuild (recommended)

If you are installing trintrin for use as part of [iCub humanoid robot software installation](https://icub-tech-iit.github.io/documentation/sw_installation/), you may want to install trintrin through the [robotology-superbuild](https://github.com/robotology/robotology-superbuild), an easy way to download, compile and install the robotology software on multiple operating systems, using the [CMake](https://www.cmake.org) build system and its extension [YCM](http://robotology.github.io/ycm). To get trintrin when using the `robotology-superbuild`, please enable the `ROBOTOLOGY_ENABLE_DYNAMICS` CMake option of the superbuild. If you want to install also trintrin Python bindings, remember to enable the `ROBOTOLOGY_USES_PYTHON` option. 

### Build from source (advanced)

If you want to build trintrin directly from source, you can can make sure that you have all the dependencies ([`ycm-cmake-modules`](https://github.com/robotology/ycm-cmake-modules), [`yarp`](https://github.com/robotology/yarp), C++ compiler and  CMake) and then install as any CMake project:

```console
git clone https://github.com/ami-iit/trintrin.git
cd trintrin
cmake -DCMAKE_INSTALL_PREFIX=<install_prefix> -Bbuild -S.
cmake --build ./build
cmake --build ./build --target install
```

If you want to compile Python bindings, make sure to install the Python and pybind11 dependencies, and enable the `TRINTRIN_COMPILE_PYTHON_BINDINGS` CMake option. 

## Use trintrin in your project

See https://github.com/robotology/human-dynamics-estimation/pull/427 for an example of using `trintrin` in your project.

## Compatibility Policy

Patch releases does not modify at all the public headers (i.e. the installed `.h` and `.hpp`) files of the project, or the messages definitions in `.msg` YARP files. This is done to ensure that no ABI change will occur in patch releases, without having to manually track ABI changes.

## Bug reports and support

All types of [issues](https://github.com/ami-iit/lie-group-controllers/issues/new) are welcome.
