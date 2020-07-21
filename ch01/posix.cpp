/*
* 作者：刘时明
* 时间：2020/7/21 0021-23:22
* 作用：
*/
#include <zconf.h>
#include "ch01.h"

void *thFunc(void *arg)
{
    int *args = (int *) arg;
    cout << "run thFunc!!! arg=" << *args << endl;
    return nullptr;
}

void posix_demo()
{
    pthread_t ti_dp;
    int args = 101;
    int ret = pthread_create(&ti_dp, nullptr, thFunc, &args);
    if (ret)
    {
        cout << "pthread_create error!" << endl;
        return;
    }
    sleep(1);
    cout << "exit" << endl;
}