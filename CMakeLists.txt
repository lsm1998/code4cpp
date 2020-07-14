cmake_minimum_required(VERSION 3.6.2)
project(code4cpp)

set(CMAKE_CXX_STANDARD 14)

# add_compile_options("-std=c++17")

add_executable(code4cpp
        main.cpp main.h
        ch01/ch01.h ch01/ch01.cpp ch01/demo.cpp ch01/sync.cpp
        ch02/ch02.h ch02/ch02.cpp ch02/base_c++.cpp ch02/read.cpp ch02/fd.cpp
        ch03/ch03.h ch03/ch03.cpp
        ch04/ch04.h ch04/ch04.cpp ch04/mongo.cpp
        ch05/ch05.cpp ch05/ch05.h ch05/pid.cpp ch05/create.cpp ch05/guardian.cpp
        ch06/ch06.cpp ch06/ch06.h)

find_package(Threads REQUIRED)
target_link_libraries(code4cpp Threads::Threads)