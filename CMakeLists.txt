cmake_minimum_required(VERSION 3.15)
project(code4cpp)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

link_libraries(ws2_32)

add_executable(code4cpp
        main.cpp main.h)