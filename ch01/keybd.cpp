/*
* 作者：刘时明
* 时间：2020/6/7-16:09
* 作用：
*/
#include <shlobj.h>
#include <fstream>
#include "ch01.h"

/**
 * 模拟一个自动打字程序
 */
void keyBdDemo()
{
    HWND hWnd=sendMsgBefore();
    // 将窗口设为系统的前台窗口
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
    // 模拟鼠标右键
    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
    Sleep(100);
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
    // 全选A
    keybd_event('A',0,0,0);

    // 保存到桌面
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