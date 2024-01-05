#!/bin/bash

if ! [[ -d build ]] then
    mkdir build
fi

cd build
cmake -DCMAKE_BUILD_TYPE=$2 -DCHESSPREFIX=$1 ..
cd ..