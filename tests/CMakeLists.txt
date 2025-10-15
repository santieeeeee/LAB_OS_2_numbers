cmake_minimum_required(VERSION 3.16)
project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(tests
    test_min_max.cpp
)

target_include_directories(tests PRIVATE ../LAB_OS_2_numbers)
target_link_libraries(tests PRIVATE gtest_main lab_numbers_lib)

include(GoogleTest)
gtest_discover_tests(tests)
