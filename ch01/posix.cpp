/*
* 作者：刘时明
* 时间：2020/7/21 0021-23:22
* 作用：
*/
#include <zconf.h>
#include "ch01.h"

void *thFunc1(void *arg)
{
    int *args = (int *) arg;
    cout << "run thFunc!!! arg=" << *args << endl;
    return nullptr;
}

void *thFunc2(void *arg)
{
    char *args = (char *) arg;
    cout << "run thFunc!!! arg=" << args << endl;
    return nullptr;
}

void posix_demo1()
{
    pthread_t ti_dp;
    int args = 101;
    char *c = (char *) "hello world!";
    int ret1 = pthread_create(&ti_dp, nullptr, thFunc1, &args);
    if (ret1)
    {
        cout << "pthread_create error!" << endl;
        return;
    }
    int ret2 = pthread_create(&ti_dp, nullptr, thFunc2, c);
    if (ret2)
    {
        cout << "pthread_create error!" << endl;
        return;
    }
    sleep(1);
    cout << "exit" << endl;
}

int gn = 10;

void *thFunc3(void *args)
{
    gn++;
    cout << "in thFunc2,gn=" << gn << endl;
    return nullptr;
}

void posix_demo2()
{
    pthread_t ti_dp;
    int ret = pthread_create(&ti_dp, nullptr, thFunc3, nullptr);
    if (ret)
    {
        cout << "pthread_create error!" << endl;
        return;
    }
    pthread_join(ti_dp, nullptr);
    gn++;
    cout << "in main:gn=" << gn << " - " << __func__ << endl;
}

void posix_demo3()
{
    pthread_t ti_dp;
    pthread_attr_t thread_attr;
    struct sched_param thread_param{};
    size_t stack_size;
    int res = pthread_attr_init(&thread_attr);
    if (res)
    {
        cout << "pthread_attr_init failed" << endl;
        return;
    }
    res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    if (res)
    {
        cout << "pthread_attr_setdetachstate failed" << endl;
        return;
    }
    res = pthread_create(&ti_dp, nullptr, thFunc3, nullptr);
    if (res)
    {
        cout << "pthread_create error!" << endl;
        return;
    }
    cout << "main exit" << endl;
    sleep(1);
}

void posix_demo4()
{
    pthread_t ti_dp;
    pthread_attr_t thread_attr;
    struct sched_param thread_param{};
    size_t stack_size;
    int res = pthread_attr_init(&thread_attr);
    if (res)
    {
        cout << "pthread_attr_init failed" << endl;
        return;
    }
    res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    if (res)
    {
        cout << "pthread_attr_setdetachstate failed" << endl;
        return;
    }
    res = pthread_create(&ti_dp, nullptr, thFunc3, nullptr);
    if (res)
    {
        cout << "pthread_create error!" << endl;
        return;
    }
    cout << "主线程退出" << endl;
    pthread_exit(nullptr);
    cout << "不会执行" << endl;
}