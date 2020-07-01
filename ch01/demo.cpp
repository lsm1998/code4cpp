#include "ch01.h"
#include <pthread.h>

#define NUM_THREADS 10

/**
 * 线程的运行函数
 * @param args
 * @return
 */
void *say_hello(void *args)
{
    cout << "Hello lsm！" << *((int *) args) << endl;
    return nullptr;
}

/**
 * 基本demo
 */
void thread_demo()
{
    pthread_t tIds[NUM_THREADS];
    // 用数组来保存i的值，如果直接传递i，由于所有i都是同一个变量，从而导致传给线程的指针都是相同的
    int indexes[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        indexes[i] = i;
        int ret = pthread_create(&tIds[i], nullptr, say_hello, (void *) &indexes[i]);
        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    // 所有线程退出才终止程序
    pthread_exit(nullptr);
}