//
// Created by 刘时明 on 2020/12/7.
//
#include <unistd.h>
#include <cstdio>

/**
 * 文件描述符
 *
 * fd 和 FILE* 的互相转换
 */
void fd_demo()
{
    FILE *f = fopen("/Users/liushiming/Desktop/1.txt", "r");
    if (f == nullptr)
    {
        printf("打开文件失败! \n");
    }

    int c;
    while ((c = fgetc(f)) != EOF)
    {
        printf("%c \n", c);
    }

    const char *str = "hello";
    // 文件指针转文件描述符
    int fd = fileno(f);
    long len = write(fd, str, 6);
    printf("%ld \n", len);

    FILE *_f = fdopen(fd, "r");
    if (_f == nullptr)
    {
        printf("打开文件失败! \n");
    }
    while ((c = fgetc(_f)) != EOF)
    {
        printf("%c \n", c);
    }
}