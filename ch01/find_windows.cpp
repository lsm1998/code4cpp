/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/7-11:19
* ���ã�
*/
#include "ch01.h"

/**
 * FindWindow����ʹ��
 * @param className
 * @param title
 */
void findWindowDemo(const char *className, const char *title)
{
    // ��ȡ���ϲ�Ĵ��ھ�����󣬲���Ϊ������������������һ������Ϊ��
    HWND hWnd = FindWindow(className, title);
    if (hWnd != nullptr)
    {
        MessageBox(nullptr, TEXT("�ҵ���"), TEXT("��ʾ"), MB_OK);
    } else
    {
        MessageBox(nullptr, TEXT("û���ҵ�"), TEXT("��ʾ"), MB_OK);
        return;
    }
    for (int i = 0; i < 100; ++i)
    {
        POINT pt;
        pt.x = pt.y = 0;
        // ��ȡλ��
        GetCursorPos(&pt);
        SetWindowPos(hWnd, nullptr, pt.x + 100, pt.y + 100, 0, 0, 1);
        Sleep(10);
    }
    if (::MessageBox(nullptr, TEXT("ȷ���ر�QQ��"), TEXT("������ʾ"), 1) == 1)
    {
        ::SendMessageA(hWnd, WM_CLOSE, 0, 0);
    }
}

