project(learn_cpp_tests)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

FILE(GLOB GLOB_TEST_CPP
        ./../*/*.test.cpp
        ./../*/*/*.test.cpp
        )

# Link runTests with what we want to test and the GTest and pthread library
add_executable(${PROJECT_NAME}
        ./main.cpp
        ${GLOB_TEST_CPP}
        )
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)