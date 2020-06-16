cmake_minimum_required(VERSION 3.15)
project(code4cpp)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

link_libraries(ws2_32)

add_executable(code4cpp
        main.cpp main.h
        ch01/ch01.cpp ch01/ch01.h main.h ch01/find_windows.cpp ch01/send.cpp ch01/frame.cpp ch01/keybd.cpp
        ch02/ch02.cpp ch02/ch02.h ch02/tcp_ser.cpp ch02/tcp_cli.cpp ch02/udp_ser.cpp ch02/udp_cli.cpp
        thread/thread.cpp thread/thread.h
        socket/socket.cpp socket/socket.h
        utils/utils.cpp utils/utils.h utils/file_util.cpp utils/file_util.h utils/socket.cpp utils/socket.h)