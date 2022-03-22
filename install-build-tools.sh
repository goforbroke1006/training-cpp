#!/bin/bash

set -e

sudo apt update

sudo apt-get install -y build-essential
gcc --version
g++ --version

sudo apt-get install -y cmake
cmake --version

sudo apt-get install -y ninja-build
ninja --version | awk '{print "ninja version " $1}'
