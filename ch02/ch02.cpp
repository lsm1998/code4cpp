/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/10-23:13
* ���ã�
*/
#include "ch02.h"

void byteSeq();

void tcpSocketServer();

void tcpSocketClient();

void ch02()
{
    byteSeq();
    tcpSocketServer();
    tcpSocketClient();
}

void byteSeq()
{
    // ͨ��ȡ�͵�ַ��ֵ�жϴ�С��
    unsigned long num = 0x01020304;
    // *(BYTE *) &num ����ȡnumǰ�ĸ��ֽ�
    if (*(BYTE *) &num == 0x04)
    {
        printf("С�� \n");
    } else
    {
        printf("��� \n");
    }

    // htons�������Խ������ֽ���ת���������ֽ���
    u_short a = 101;
    printf("%d \n", htons(a));
    u_long b = 101;
    printf("%lu \n", ntohl(b));
}