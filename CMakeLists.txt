cmake_minimum_required(VERSION 3.15)
project(LAB_OS_2_numbers_root LANGUAGES CXX)

if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL" CACHE STRING "" FORCE)
endif()

add_subdirectory(LAB_OS_2_numbers)
add_subdirectory(tests)
