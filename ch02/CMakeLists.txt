project(ch02)

set(src 
${CMAKE_CURRENT_SOURCE_DIR}/ch02.h
${CMAKE_CURRENT_SOURCE_DIR}/ch02.cpp
${CMAKE_CURRENT_SOURCE_DIR}/tcp_cli.cpp
${CMAKE_CURRENT_SOURCE_DIR}/tcp_ser.cpp
${CMAKE_CURRENT_SOURCE_DIR}/udp_ser.cpp
${CMAKE_CURRENT_SOURCE_DIR}/udp_cli.cpp
)

add_executable(ch02 ${src})