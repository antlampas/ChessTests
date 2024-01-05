#!/bin/bash

if ! [[ -d build ]] then
    mkdir build
fi

units=""

for flag in "${@:2}"
do
    units+=" -D${flag}"
done


cd build
cmake -DCMAKE_BUILD_TYPE=$1 ${units} ..
cd ..