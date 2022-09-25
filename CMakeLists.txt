cmake_minimum_required(VERSION 3.12)
project(learn-cpp)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(03-inverted-list)
add_subdirectory(04-quick-sort)
add_subdirectory(05-two-num-sum)
add_subdirectory(06-two-num-nearest-sum)

enable_testing()
add_subdirectory(tests)
