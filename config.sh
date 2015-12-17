#! /bin/bash

mkdir -p build
cd build
rm -rf *

mkdir Release
cd Release
cmake -DCMAKE_BUILD_TYPE=Release ../../source
make

cd ..

mkdir Debug
cd Debug
cmake -DCMAKE_BUILD_TYPE=Debug ../../source
make
