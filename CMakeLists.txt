cmake_minimum_required(VERSION 3.8)
project(code4cpp)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_subdirectory(ch01)