cmake_minimum_required(VERSION 3.17.3)
project(code4cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_subdirectory(ch01)
add_subdirectory(ch03)
add_subdirectory(echos)
add_subdirectory(kqueue)
add_subdirectory(mysql)