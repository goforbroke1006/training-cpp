cmake_minimum_required(VERSION 3.12)
project(learn-cpp)

set(CMAKE_CXX_STANDARD 14)

#
# Download and install GTest
#
set(GTEST_VERSION 1.12.0)
if (NOT EXISTS ${PROJECT_BINARY_DIR}/googletest-release-${GTEST_VERSION})
    message(STATUS "Installing GTest")
    set(GTEST_ARCHIVE_FILENAME googletest-v${GTEST_VERSION}.zip)

    if (NOT EXISTS ${PROJECT_BINARY_DIR}/googletest-${GTEST_VERSION}.tar.gz)
        message(STATUS "Download " https://github.com/google/googletest/archive/refs/tags/release-${GTEST_VERSION}.zip)
        file(DOWNLOAD https://github.com/google/googletest/archive/refs/tags/release-${GTEST_VERSION}.zip ${PROJECT_BINARY_DIR}/${GTEST_ARCHIVE_FILENAME})
    endif ()

    message(STATUS "Building GTest")
    execute_process(COMMAND ${CMAKE_COMMAND} -E tar xf ${GTEST_ARCHIVE_FILENAME} WORKING_DIRECTORY ${PROJECT_BINARY_DIR})
    execute_process(COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} ${PROJECT_BINARY_DIR}/googletest-release-${GTEST_VERSION} -Dgtest_force_shared_crt=TRUE -DBUILD_GMOCK=FALSE WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/googletest-release-${GTEST_VERSION})
    execute_process(COMMAND ${CMAKE_COMMAND} --build ${PROJECT_BINARY_DIR}/googletest-release-${GTEST_VERSION})
endif ()

#
# Add includes, sources and libraries on GTest
#
set(GTEST_INCLUDE_DIR ${PROJECT_BINARY_DIR}/googletest-release-${GTEST_VERSION}/googletest/include)
set(gtest_SOURCE_DIR ${PROJECT_BINARY_DIR}/googletest-release-${GTEST_VERSION}/googletest/src)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(GTEST_LIBRARY ${PROJECT_BINARY_DIR}/googletest-release-${GTEST_VERSION}/lib/libgtest.a)
    set(GTEST_MAIN_LIBRARY ${PROJECT_BINARY_DIR}/googletest-release-${GTEST_VERSION}/lib/libgtest_main.a)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(GTEST_LIBRARY ${PROJECT_BINARY_DIR}/googletest-release-${GTEST_VERSION}/lib/gtest.lib)
    set(GTEST_MAIN_LIBRARY ${PROJECT_BINARY_DIR}/googletest-release-${GTEST_VERSION}/lib/gtest_main.lib)
endif ()


add_subdirectory(exercise/03-inverted-list)
add_subdirectory(exercise/04-quick-sort)
add_subdirectory(exercise/05-two-num-sum)
add_subdirectory(exercise/06-two-num-nearest-sum)
add_subdirectory(exercise/07-merge-sort)

add_subdirectory(algorithms-for-beginners-book/ch-1-quote-span)


enable_testing()
add_subdirectory(tests)
