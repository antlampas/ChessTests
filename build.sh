#!/bin/bash

if ! [[ -d build ]] then
    mkdir build
fi

units=""

for flag in "${@:3}"
do
    units+=" ${flag}"
done

cd build
cmake -DCMAKE_BUILD_TYPE="${1}" -DVERSION="${2}" -DUNITS="${units}" ..
cd ..