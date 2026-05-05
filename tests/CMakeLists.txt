cmake_minimum_required(VERSION 3.14)

project(tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../include)

enable_testing()

add_executable(tests test_cs.cpp test_math.cpp ..src/math/core.cpp ../src/cs/core.cpp ..src/math/statistics.cpp)
target_link_libraries(tests Gtest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)

add_custom_target(testall ALL
    DEPENDS tests
    COMMAND tests
)