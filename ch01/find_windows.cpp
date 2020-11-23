/*
* 作者：刘时明
* 时间：2020/6/7-11:19
* 作用：
*/
#include "ch01.h"

/**
 * FindWindow基本使用
 * @param className
 * @param title
 */
void findWindowDemo(const char *className, const char *title)
{
    // 获取最上层的窗口句柄对象，参数为类名、标题名，其中一个可以为空
    HWND hWnd = FindWindow(className, title);
    if (hWnd != nullptr)
    {
        MessageBox(nullptr, TEXT("找到了"), TEXT("提示"), MB_OK);
    } else
    {
        MessageBox(nullptr, TEXT("没有找到"), TEXT("提示"), MB_OK);
        return;
    }
    for (int i = 0; i < 100; ++i)
    {
        POINT pt;
        pt.x = pt.y = 0;
        // 获取位置
        GetCursorPos(&pt);
        SetWindowPos(hWnd, nullptr, pt.x + 100, pt.y + 100, 0, 0, 1);
        Sleep(10);
    }
    if (::MessageBox(nullptr, TEXT("确定关闭QQ吗？"), TEXT("操作提示"), 1) == 1)
    {
        ::SendMessageA(hWnd, WM_CLOSE, 0, 0);
    }
}

