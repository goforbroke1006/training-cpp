cmake_minimum_required(VERSION 3.12)
project(learn-cpp)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(01-invert-list)
add_subdirectory(02-inverted-linked-list)

enable_testing()
add_subdirectory(tests)
