//
// Created by 刘时明 on 2020/11/28.
//
#include "ch01.h"

int main()
{
    short a = 0x0102;
    char b = (char) a;
    if (b == 0x01)
    {
        printf("小端 \n");
    }
    if (b == 0x02)
    {
        printf("大端 \n");
    }
    printf("%d \n", b);

    show_dir((char*)"/etc");

    shell();
    return 0;
}
