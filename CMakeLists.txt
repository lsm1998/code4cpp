cmake_minimum_required(VERSION 3.8)
project(code4cpp)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

link_libraries(ws2_32)

add_subdirectory(ch01)
add_subdirectory(ch02)
add_subdirectory(ch03)
add_subdirectory(ch04)