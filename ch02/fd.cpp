/*
* 作者：刘时明
* 时间：2020/7/6 0006-21:45
* 作用：
*/
#include "ch02.h"

void file_fd()
{
    cout << fileno(stdin) << endl;

    cout << fileno(stdout) << endl;

    cout << fileno(stderr) << endl;

    FILE *file = fdopen(fileno(stdin), "r");
    cout << file->_mode << endl;
}