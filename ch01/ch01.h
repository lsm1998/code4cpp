/*
* 作者：刘时明
* 时间：2020/6/6-13:18
* 作用：
*/
#ifndef CPP4WINDOWS_CH01_H
#define CPP4WINDOWS_CH01_H

#include <windows.h>
#include <iostream>

#define MY_MSG WM_USER+1

using namespace std;

void ch01(HINSTANCE hInstance,
          HINSTANCE hPrevInstance,
          LPSTR lpCmdLine,
          int nCmdShow);

HWND sendMsgBefore();

void findWindowDemo(const char *className, const char *title);

void sendMsgDemo();

int frameDemo(HINSTANCE hInstance);

void keyBdDemo();

#endif //CPP4WINDOWS_CH01_H
