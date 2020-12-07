project(mysql)

# 添加boost头文件搜索路径
include_directories(/usr/local/Cellar/boost/1.74.0/include)
# mysql连接器
include_directories(/usr/local/mysql-connector-c++/include)
# 添加boost库文件搜索路径
link_directories(/usr/local/Cellar/boost/1.74.0/lib)
# mysql连接器
include_directories(/usr/local/mysql-connector-c++/lib64)

#用于将当前目录下的所有源文件的名字保存在变量 DIR_SRCS 中
aux_source_directory(. DIR_SRCS)

add_executable(mysql ${DIR_SRCS})

target_link_libraries(mysql mysqlcppconn-static ssl crypto)