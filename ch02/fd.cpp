//
// Created by 刘时明 on 2020/12/7.
//
#include <unistd.h>
#include <cstdio>

void fd_demo()
{
    FILE *f = fopen("/Users/liushiming/Desktop/hello.java", "r");
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
    int fd = fileno(f);
    long len=write(fd, str, 6);
    printf("%ld \n",len);
}