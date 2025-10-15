cmake_minimum_required(VERSION 3.8)
project(LAB_OS_2_numbers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(lab_numbers_lib
    LAB_OS_2_numbers.cpp
)

target_compile_definitions(lab_numbers_lib PRIVATE UNIT_TEST)
target_include_directories(lab_numbers_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(LAB_OS_2_numbers
    LAB_OS_2_numbers.cpp
)

target_link_libraries(LAB_OS_2_numbers PRIVATE lab_numbers_lib)
