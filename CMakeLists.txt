cmake_minimum_required(VERSION 3.16)
project(code4cpp)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(include)

# 为TRUE时，打包可执行文件没有命令窗口
set(useWin32 TRUE)

if (WINDOWS)
    set(CMAKE_PREFIX_PATH D:/Qt/Qt5.13.2/5.13.2/mingw73_64/lib/cmake)
endif ()

if(UNIX OR Linux)
    set(CMAKE_PREFIX_PATH opt/Qt/Qt5.13.2/5.13.2/mingw73_64/lib/cmake)
endif ()

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

if (selfWidgetCompile)
    #自定义控件库编译
    add_library(${PROJECT_NAME} SHARED ${PATH_LIB})
else ()
    aux_source_directory(./ PATH_RES)
    if (useWin32)
        add_executable(${PROJECT_NAME} WIN32 ${PATH_RES} ${PATH_LIB})
    else ()
        add_executable(${PROJECT_NAME} ${PATH_RES} ${PATH_LIB})
    endif ()
endif ()

target_link_libraries(
        code4cpp
        Qt5::Widgets
        Qt5::Core
        Qt5::Gui
)

if(UNIX OR Linux)
    target_link_libraries(${name} pthread)
endif()

qt5_use_modules(code4cpp Core Widgets Gui)