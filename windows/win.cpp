#include "win.h"

#pragma comment (lib, "User32.lib")

int WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow
)
{
    // ����API���� MessageBox
    MessageBox(NULL,
               TEXT("��ʼѧϰWindows���"),
               TEXT("��Ϣ�Ի���"),
               MB_OK);
    return 0;
}