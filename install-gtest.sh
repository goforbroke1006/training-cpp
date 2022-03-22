#!/bin/bash

set -e

sudo apt update

sudo apt-get install -y libgtest-dev
dpkg -l | grep libgtest-dev | awk '{print "libgtest-dev version " $3}'

#sudo apt-get install -y cmake
#(
#  cd /usr/src/gtest || exit 1
#  sudo cmake CMakeLists.txt
#  sudo make
##  sudo cp ./*.a /usr/lib || true
##  sudo cp ./lib/*.a /usr/lib || true
#  find ./ -name '*.a' -type f -exec sudo cp {} /usr/lib/ \;
#  sudo ldconfig
#)
