/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/7-11:49
* ���ã�
*/
#include "ch01.h"

/**
 * SendMessage ������Ϣ��ָ���Ĵ��ھ������
 * param1 ���ھ��
 * param2 ��Ϣ����
 * param3 ���Ӳ���1
 * param4 ���Ӳ���2
 */
void sendMsgDemo()
{
    HWND hWnd=sendMsgBefore();
    string text("���ǲ�������");
    // ���ñ���
    SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM) text.c_str());
    // ��ȡ����
    char title[1024];
    SendMessageA(hWnd, WM_GETTEXT, 1024, (LPARAM)title);
    cout << "title=" << title << endl;
    Sleep(5*1000);
    // �ر�
    SendMessage(hWnd, WM_CLOSE, 0, 0);
}

HWND sendMsgBefore()
{
    WinExec("notepad.exe", SW_SHOW);
    HWND hWnd = FindWindow("Notepad", "�ޱ��� - ���±�");
    if (hWnd == nullptr)
    {
        MessageBox(nullptr, TEXT("û���ҵ����±�"), TEXT("��ʾ"), MB_OK);
        exit(0);
    }
    return hWnd;
}