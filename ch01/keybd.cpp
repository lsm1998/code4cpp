/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/7-16:09
* ���ã�
*/
#include <shlobj.h>
#include <fstream>
#include "ch01.h"

/**
 * ģ��һ���Զ����ֳ���
 */
void keyBdDemo()
{
    HWND hWnd=sendMsgBefore();
    // ��������Ϊϵͳ��ǰ̨����
    SetForegroundWindow(hWnd);
    SendMessage(hWnd, WM_SETTEXT, 0 , (LPARAM) "hello");
    keybd_event('I',0,0,0);
    keybd_event(0x20,0,0,0);
    Sleep(1000);
    keybd_event('L',0,0,0);
    keybd_event('O',0,0,0);
    keybd_event('V',0,0,0);
    keybd_event('E',0,0,0);
    keybd_event(0x20,0,0,0);
    Sleep(1000);
    keybd_event('Y',0,0,0);
    keybd_event('O',0,0,0);
    keybd_event('U',0,0,0);

    POINT pt={0};
    ClientToScreen(hWnd,&pt);

    SetCursorPos(pt.x,pt.y);
    // ģ������Ҽ�
    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
    Sleep(100);
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
    // ȫѡA
    keybd_event('A',0,0,0);

    // ���浽����
    char path[255];
    SHGetSpecialFolderPath(nullptr,path,CSIDL_DESKTOPDIRECTORY,0);
    strcat(path,"\\hello.txt");
    fstream output(path, ios::out | ios::binary);
    if(output.is_open())
    {
        output.write("fuck you!",9);
        output.close();
    }
}