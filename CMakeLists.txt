cmake_minimum_required(VERSION 3.10)
project(code4cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(code4cpp
        main.cpp main.h
        ch01/ch01.h ch01/ch01.cpp ch01/demo.cpp ch01/sync.cpp ch01/thread.cpp)

find_package(Threads REQUIRED)
target_link_libraries(code4cpp Threads::Threads)