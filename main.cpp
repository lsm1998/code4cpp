#include <iostream>
#include "main.h"

using namespace std;

int WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow)
{
    cout << "win32" << endl;
    ch01(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
    return 0;
}

/**
 * Òþ²ØCMD´°¿Ú
 */
void hideCmdDos()
{
    /**
     * vs: #pragma comment( linker, "/subsystem:/"windows/" /entry:/"mainCRTStartup/"" )
     */
    HWND hwndDOS = GetForegroundWindow();
    ShowWindow(hwndDOS, SW_HIDE);
}