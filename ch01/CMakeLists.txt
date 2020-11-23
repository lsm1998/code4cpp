project(ch01)

set(src 
${CMAKE_CURRENT_SOURCE_DIR}/ch01.h
${CMAKE_CURRENT_SOURCE_DIR}/ch01.cpp
${CMAKE_CURRENT_SOURCE_DIR}/find_windows.cpp
${CMAKE_CURRENT_SOURCE_DIR}/frame.cpp
${CMAKE_CURRENT_SOURCE_DIR}/keybd.cpp
${CMAKE_CURRENT_SOURCE_DIR}/send.cpp
)

add_executable(ch01 ${src})