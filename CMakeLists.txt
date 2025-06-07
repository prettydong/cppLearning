cmake_minimum_required(VERSION 3.14)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HelloWorld src/main.cpp)

# --- Google Test Integration ---
include(FetchContent)
enable_testing()

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/v1.14.0.zip
)

# For modern CMake targets, it's recommended to use this form:
FetchContent_MakeAvailable(googletest)

# Create the test executable
add_executable(runTests test/math_test.cpp)

# Link the test executable against Google Test
target_link_libraries(
  runTests
  GTest::gtest_main
)

# Add the test to be run with `ctest`
include(GoogleTest)
gtest_discover_tests(runTests) 