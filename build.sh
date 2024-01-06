#!/bin/bash

if ! [[ -d build ]] then
    mkdir build
fi

units=""

for flag in "${@:2}"
do
    units+=" ${flag}"
done

cd build
cmake -DCMAKE_BUILD_TYPE=$1 -DUNITS="${units}" ..
cd ..