/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/2-0:18
* ���ã�
*/
#include <stdio.h>
#include <windows.h>
#include "ch11.h"

void ch11()
{
//    char *c = NULL;
//    scanf("%s", c);
    printf("��ʼ \n");
    HWND win = FindWindowA("TXGuiFoundation", "QQ");
    while (1)
    {
        POINT pt;
        pt.x = pt.y = 0;
        // ��ȡλ��
        GetCursorPos(&pt);
        SetWindowPos(win, NULL, pt.x + 100, pt.y + 100,0, 0, 1);
        Sleep(50);
    }
}

