/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/2-0:18
* ���ã�
*/
#include <windows.h>
#include "ch11.h"

void ch11()
{

    HWND hwndDOS = GetForegroundWindow();
    ShowWindow(hwndDOS, SW_HIDE);
    while (true)
    {
        HWND win = FindWindowA("TXGuiFoundation", "QQ");
        POINT pt;
        pt.x = pt.y = 0;
        // ��ȡλ��
        GetCursorPos(&pt);
        SetWindowPos(win, NULL, pt.x + 100, pt.y + 100,0, 0, 1);
        Sleep(100);
    }
}

