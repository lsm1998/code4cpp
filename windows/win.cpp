#include <windows.h>
#include <string>
#include "win.h"
#include "key_board.h"

#define CLASSNAME "����"
//  #pragma comment (lib, "User32.lib")

LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam);

ATOM MyRegisterClass(HINSTANCE hInstance);

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

int show_frame(HINSTANCE hInstance);

void exec_notepad();

/**
 * WinMain ��windows����Ӧ�õ�������
 * @param hInstance Ӧ�ó���ʵ�����
 * @param hPrevInstance ͬһ���ļ���������һ��ʵ���ľ����win16��������win32����
 * @param lpCmdLine �����������в���
 * @param nCmdShow ������ʾ��ʽ����󻯡���С�������ص�
 * @return
 */
int WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow
)
{
    exec_notepad();
    // show_frame(hInstance);
    return 0;
}

/**
 * ��ʾ����
 * @param hInstance
 * @return
 */
int show_frame(HINSTANCE hInstance)
{
    MSG msg;
    BOOL bRet;
    // ע�ᴰ����
    MyRegisterClass(hInstance);

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

/**
 * ��Ϣ���ü��±�
 */
void exec_notepad()
{
    auto *d = new CMsgTestDlg();
    d->OnExec();
    // d->OnClose();
    d->OnEditWnd();
    // d->OnGetWnd();
    start("��Ϣ����");
}

ATOM MyRegisterClass(HINSTANCE hInstance)
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
    WndCls.hCursor = LoadCursor(NULL, IDC_ARROW);
    // hIcon��ͼ����
    WndCls.hIcon = LoadIcon(NULL, IDI_QUESTION);
    // ����
    WndCls.cbClsExtra = 0;
    WndCls.cbWndExtra = 0;
    return RegisterClassEx(&WndCls);
}

LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hDC;
    RECT rt;
    const CHAR *pszDrawText = "Hello Windows Program.";
    // char *pszDrawText = "Hello Windows Program.";
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
            if (IDYES == MessageBox(hwnd,
                                    "�Ƿ��˳�����", "MyFirstWin", MB_YESNO))
            {
                DestroyWindow(hwnd);
                PostQuitMessage(0);
            }
            break;
        }
        default:
        {
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }
    return 0;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    HWND hWnd = NULL;

    // ��������
    hWnd = CreateWindowEx(WS_EX_CLIENTEDGE,
                          CLASSNAME,
                          "MyFirstWindow",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL);

    if (NULL == hWnd)
    {
        return FALSE;
    }
    // ��ʾ����
    ShowWindow(hWnd, nCmdShow);
    // ���´���
    UpdateWindow(hWnd);
    return TRUE;
}

void CMsgTestDlg::OnClose()
{
    HWND hwnd = ::FindWindow("Notepad", nullptr);
    if (hwnd == nullptr)
    {
        // ����API���� MessageBox
        MessageBox(nullptr,
                   TEXT("û���ҵ����±�"),
                   TEXT("��ʾ"),
                   MB_OK);
    } else
    {
        WPARAM null_point = 0;
        ::SendMessage(hwnd, WM_CLOSE, null_point, null_point);
    }
}

void CMsgTestDlg::OnExec()
{
    WinExec("notepad.exe", SW_SHOW);
}

void CMsgTestDlg::OnEditWnd()
{
    HWND hWnd = ::FindWindow(nullptr, "�ޱ��� - ���±�");
    if (hWnd == nullptr)
    {
        MessageBox(nullptr, TEXT("û���ҵ����±�"), TEXT("��ʾ"), MB_OK);
        return;
    }
    std::string pCaptionText = "��Ϣ����";
    ::SendMessage(hWnd, WM_SETTEXT, (WPARAM) 0, (LPARAM) pCaptionText.c_str());
}

void CMsgTestDlg::OnGetWnd()
{
    HWND hWnd = ::FindWindow("Notepad", nullptr);
    if (hWnd == nullptr)
    {
        MessageBox(nullptr, TEXT("û���ҵ����±�"), TEXT("��ʾ"), MB_OK);
        return;
    }
    char pCaptionText[MAXBYTE] = {0};
    ::SendMessage(hWnd, WM_GETTEXT, (WPARAM) MAXBYTE, (LPARAM) pCaptionText);
    MessageBox(nullptr, TEXT(pCaptionText), TEXT("��ʾ"), MB_OK);
}