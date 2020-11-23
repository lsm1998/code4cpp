/*
* 作者：刘时明
* 时间：2020/6/7-11:49
* 作用：
*/
#include "ch01.h"

/**
 * SendMessage 发送消息给指定的窗口句柄对象
 * param1 窗口句柄
 * param2 消息类型
 * param3 附加参数1
 * param4 附加参数2
 */
void sendMsgDemo()
{
    HWND hWnd=sendMsgBefore();
    string text("这是测试内容");
    // 设置标题
    SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM) text.c_str());
    // 获取标题
    char title[1024];
    SendMessageA(hWnd, WM_GETTEXT, 1024, (LPARAM)title);
    cout << "title=" << title << endl;
    Sleep(5*1000);
    // 关闭
    SendMessage(hWnd, WM_CLOSE, 0, 0);
}

HWND sendMsgBefore()
{
    WinExec("notepad.exe", SW_SHOW);
    HWND hWnd = FindWindow("Notepad", "无标题 - 记事本");
    if (hWnd == nullptr)
    {
        MessageBox(nullptr, TEXT("没有找到记事本"), TEXT("提示"), MB_OK);
        exit(0);
    }
    return hWnd;
}