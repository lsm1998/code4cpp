//
// Created by 刘时明 on 2020/12/6.
//
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>

void create_file()
{
    int fd = open("/Users/liushiming/Desktop/hello.java", O_CREAT);
    close(fd);
}

/*
 * 文件描述符的拷贝
 */
void copy_fd()
{
    int fd = open("/Users/liushiming/Desktop/hello.java", O_RDONLY);
    // 偏移6个字节，看看是否对拷贝的文件描述符有效
    lseek(fd, 6, SEEK_CUR);
    if (fd < 0)
    {
        printf("open file fail!");
    }
    int _fd = dup(fd);
    char buff[512];
    read(_fd, buff, 512);
    printf("%s \n", buff);
    // 使用fcntl函数拷贝
    int _fd2 = fcntl(fd, F_DUPFD, 0);
    read(_fd2, buff, 512);
    printf("%s \n", buff);
}