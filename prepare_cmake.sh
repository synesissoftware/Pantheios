#! /bin/bash

Dir=$(cd $(dirname "$0"); pwd)
Basename=$(basename "$0")
CMakePath=$Dir/_build

mkdir -p $CMakePath

cd $CMakePath

echo "Executing CMake"

cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ..

echo "Executing make"

make

cd ..

ls -al $CMakePath

