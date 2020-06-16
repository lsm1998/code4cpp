/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/7-14:20
* ���ã�
*/
#include "ch01.h"

#define CLASSNAME "�ҵĴ�����"

LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam);

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

void registerWnd(HINSTANCE hInstance);

int frameDemo(HINSTANCE hInstance)
{
    // ����
    MSG msg;
    BOOL bRet;

    registerWnd(hInstance);

    // �������ڲ���ʾ����
    if (!InitInstance(hInstance, SW_SHOWNORMAL))
    {
        return FALSE;
    }

    // ��Ϣѭ��
    // ��ȡ�����Լ�����Ϣ�����зַ�
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
    // ���ṹ��Ϊ0
    ZeroMemory(&WndCls, sizeof(WNDCLASSEX));
    // cbSize�ǽṹ���С
    WndCls.cbSize = sizeof(WNDCLASSEX);
    // lpfnWndProc�Ǵ��ڹ��̵�ַ
    WndCls.lpfnWndProc = WindowProc;
    // hInstance��ʵ�����
    WndCls.hInstance = hInstance;
    // lpszClassName�Ǵ���������
    WndCls.lpszClassName = CLASSNAME;
    // style�Ǵ�������
    WndCls.style = CS_HREDRAW | CS_VREDRAW;
    // hbrBackground�Ǵ����౳��ɫ
    WndCls.hbrBackground = (HBRUSH) COLOR_WINDOWFRAME + 1;
    // hCursor�������
    WndCls.hCursor = LoadCursor(nullptr, IDC_ARROW);
    // hIcon��ͼ����
    WndCls.hIcon = LoadIcon(nullptr, IDI_QUESTION);
    // ����
    WndCls.cbClsExtra = 0;
    WndCls.cbWndExtra = 0;
    RegisterClassEx(&WndCls);
}

/**
 * ������Ϣ�Ĵ��ڹ���
 * @param hwnd ���ھ��
 * @param uMsg ��Ϣ����
 * @param wParam ����1
 * @param lParam ����2
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
    const CHAR *pszDrawText = "��ð�";
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
            if (IDYES == MessageBox(hwnd,"�Ƿ��˳�����", "MyFirstWin", MB_YESNO))
            {
                cout << "�˳�" << endl;
                // �˳�����
                DestroyWindow(hwnd);
                // �˳�����
                PostQuitMessage(0);
            }
            break;
        }
        default:
        {
            // δ�Զ��崦��Ľ���Ĭ�ϴ��ڹ���
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }
    return 0;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    HWND hWnd;
    // ��������
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
    // ��ʾ����
    ShowWindow(hWnd, nCmdShow);
    // ���´���
    UpdateWindow(hWnd);
    return TRUE;
}