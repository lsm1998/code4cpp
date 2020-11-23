/*
* 作者：刘时明
* 时间：2020/6/10-23:13
* 作用：
*/
#include "ch02.h"

void byteSeq();

void tcpSocketServer();

void tcpSocketClient();

void byteSeq()
{
    // 通过取低地址的值判断大小端
    unsigned long num = 0x01020304;
    // *(BYTE *) &num 就是取num前四个字节
    if (*(BYTE *) &num == 0x04)
    {
        printf("小端 \n");
    } else
    {
        printf("大端 \n");
    }

    // htons函数可以将主机字节序转换成网络字节序
    u_short a = 101;
    printf("%d \n", htons(a));
    u_long b = 101;
    printf("%lu \n", ntohl(b));
}

int main()
{
    printf("hello\n");
    byteSeq();
    tcpSocketServer();
    tcpSocketClient();
    return 0;
}