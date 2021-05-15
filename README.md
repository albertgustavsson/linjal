# Linjal
A C++ library for linear algebra

## Building
CMake is used for building the library.
Build files should be put in the directory `build`.
Example of commands to generate build files:
```sh
mkdir build
cd build
cmake ..
```

## Goals
The goal of this library is to provide code for common operations in linear algebra.
A secondary goal is to have the library use OpenCL for GPU acceleration when available on the system.