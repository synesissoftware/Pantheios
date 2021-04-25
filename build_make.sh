#! /bin/bash

Dir=$(cd $(dirname "$0"); pwd)
Basename=$(basename "$0")
CMakePath=$Dir/_build

mkdir -p $CMakePath || exit 1

cd $CMakePath

cmake .. || exit 1

echo "Executing make"

make

cd -

ls -al $CMakePath

