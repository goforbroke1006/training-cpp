#!/bin/bash

set -e

sudo apt-get install -y libgtest-dev

sudo apt-get install -y cmake
(
  cd /usr/src/gtest || exit 1
  sudo cmake CMakeLists.txt
  sudo make
  sudo cp ./*.a /usr/lib
  sudo cp ./lib/*.a /usr/lib
  sudo ldconfig
)
