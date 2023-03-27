#GOOGLE UNIT TESTING
cmake_minimum_required(VERSION 3.22)

# 'Google_test' is the subproject name
project(unit_testing)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(RunallTests GameTest.cpp runAllTests.cpp)

target_link_libraries(RunallTests gtest gtest_main core)