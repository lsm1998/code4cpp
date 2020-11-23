/*
* 作者：刘时明
* 时间：2020/6/7-14:20
* 作用：
*/
#include "ch01.h"

#define CLASSNAME "我的窗口类"

LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam);

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

void registerWnd(HINSTANCE hInstance);

int frameDemo(HINSTANCE hInstance)
{
    // 定义
    MSG msg;
    BOOL bRet;

    registerWnd(hInstance);

    // 创建窗口并显示窗口
    if (!InitInstance(hInstance, SW_SHOWNORMAL))
    {
        return FALSE;
    }

    // 消息循环
    // 获取属于自己的消息并进行分发
    while ((bRet = GetMessage(&msg, nullptr, 0, 0)) != 0)
    {
        if (bRet == -1)
        {
            // handle the error and possibly exit
            break;
        } else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return msg.wParam;
}

void registerWnd(HINSTANCE hInstance)
{
    WNDCLASSEX WndCls;
    // 填充结构体为0
    ZeroMemory(&WndCls, sizeof(WNDCLASSEX));
    // cbSize是结构体大小
    WndCls.cbSize = sizeof(WNDCLASSEX);
    // lpfnWndProc是窗口过程地址
    WndCls.lpfnWndProc = WindowProc;
    // hInstance是实例句柄
    WndCls.hInstance = hInstance;
    // lpszClassName是窗口类类名
    WndCls.lpszClassName = CLASSNAME;
    // style是窗口类风格
    WndCls.style = CS_HREDRAW | CS_VREDRAW;
    // hbrBackground是窗口类背景色
    WndCls.hbrBackground = (HBRUSH) COLOR_WINDOWFRAME + 1;
    // hCursor是鼠标句柄
    WndCls.hCursor = LoadCursor(nullptr, IDC_ARROW);
    // hIcon是图标句柄
    WndCls.hIcon = LoadIcon(nullptr, IDI_QUESTION);
    // 其他
    WndCls.cbClsExtra = 0;
    WndCls.cbWndExtra = 0;
    RegisterClassEx(&WndCls);
}

/**
 * 处理消息的窗口过程
 * @param hwnd 窗口句柄
 * @param uMsg 消息类型
 * @param wParam 参数1
 * @param lParam 参数2
 * @return
 */
LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hDC;
    RECT rt;
    const CHAR *pszDrawText = "你好啊";
    switch (uMsg)
    {
        case WM_PAINT:
        {
            hDC = BeginPaint(hwnd, &ps);
            GetClientRect(hwnd, &rt);
            DrawTextA(hDC,
                      pszDrawText, strlen(pszDrawText), &rt,
                      DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            EndPaint(hwnd, &ps);
            break;
        }
        case WM_CLOSE:
        {
            if (IDYES == MessageBox(hwnd,"是否退出程序", "MyFirstWin", MB_YESNO))
            {
                cout << "退出" << endl;
                // 退出窗口
                DestroyWindow(hwnd);
                // 退出程序
                PostQuitMessage(0);
            }
            break;
        }
        default:
        {
            // 未自定义处理的交给默认窗口过程
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }
    return 0;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    HWND hWnd;
    // 创建窗口
    hWnd = CreateWindowEx(WS_EX_CLIENTEDGE,
                          CLASSNAME,
                          "hello",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          nullptr, nullptr, hInstance, nullptr);

    if (nullptr == hWnd)
    {
        return FALSE;
    }
    // 显示窗口
    ShowWindow(hWnd, nCmdShow);
    // 更新窗口
    UpdateWindow(hWnd);
    return TRUE;
}