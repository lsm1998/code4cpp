/*
* 作者：刘时明
* 时间：2020/7/8 0008-21:56
* 作用：
*/
#include "ch05.h"

void pid_demo();

void fork_demo();

void exec_demo();

int system_demo(const char *cmdString);

void guardian();

void ch05()
{
    cout << "hello " << endl;

    exec_demo();

    guardian();
}