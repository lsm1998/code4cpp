cmake_minimum_required(VERSION 3.18.0)
project(code4cpp)

set(CMAKE_CXX_STANDARD 20)

set(INC_DIR /usr/local/include)
set(LINK_DIR /usr/local/lib)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})

add_executable(code4cpp
        main.cpp main.h
        ch01/ch01.h ch01/ch01.cpp ch01/demo.cpp ch01/sync.cpp ch01/pool.cpp ch01/posix.cpp ch01/pool.h
        ch02/ch02.h ch02/ch02.cpp ch02/base_c++.cpp ch02/read.cpp ch02/fd.cpp
        ch03/ch03.h ch03/ch03.cpp ch03/socket.cpp ch03/ip.cpp ch03/tcp_client.cpp ch03/tcp_server.cpp
        ch04/ch04.h ch04/ch04.cpp ch04/mongo.cpp
        ch05/ch05.cpp ch05/ch05.h ch05/pid.cpp ch05/create.cpp ch05/guardian.cpp
        ch06/ch06.cpp ch06/ch06.h ch06/signal.cpp ch06/pipe.cpp
        ch07/ch07.cpp ch07/ch07.h
        ch08/ch08.cpp ch08/ch08.h ch08/json.cpp)

find_package(Threads REQUIRED)
target_link_libraries(code4cpp Threads::Threads jsoncpp)