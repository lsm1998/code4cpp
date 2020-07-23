#include <thread>
#include <unistd.h>
#include <mutex>
#include "ch01.h"

#define TICKET_WORK 100

// 车票资源
int ticket;
// 业绩
int achievement[TICKET_WORK];

auto *mut = new mutex();

/**
 * 实现简单的打印
 * @param args
 * @param loop
 */
void thread_func(const string &args, int loop)
{
    for (int i = 0; i < loop; ++i)
    {
        cout << "线程执行，收到参数: " << args << endl;
        usleep(5);
    }
}

/**
 * 设置同步的售票函数
 * @param name
 */
void sell_ticket(const int &index)
{
    while (ticket > 0)
    {
        mut->lock();
        if (ticket <= 0)
        {
            mut->unlock();
            break;
        }
        cout << "窗口 " << index << " 出售了一张车票，当前剩余" << --ticket << endl;
        achievement[index]++;
        mut->unlock();
        usleep(1000);
    }
    cout << "窗口 " << index << " 退出" << endl;
}

void std_thread()
{
    int threadNum = thread::hardware_concurrency();
    cout << "CPU线程数=" << threadNum << endl;

    thread t1(thread_func, "1", 10);
    thread t2(thread_func, "2", 10);
    thread t3(thread_func, "3", 10);
    thread t4(thread_func, "4", 10);
    // 对于线程而言，在生命周期内任意时间点线程是可结合的（joinable），或者是分离的（detached）
    // 一个可结合的线程能够被其他线程收回其资源和杀死；在被其他线程回收之前，它的存储器资源（如栈）是不释放的
    // 一个分离的线程是不能被其他线程回收或杀死的，它的存储器资源在它终止时由系统自动释放
    // joinable()返回线程是否可结合，默认情况返回true
    cout << "joinable=" << t1.joinable() << endl;

    // 启动线程的方式有2种，即detach分离线程和join连接线程
    t1.detach();
    t2.detach();
    t3.detach();
    t4.detach();

    // 如果采用join的方式，则不需要睡眠等待
    sleep(2);

    // 初始化10000张车票
    ticket = 10000;

    for (int i = 0; i < TICKET_WORK; ++i)
    {
        thread temp(sell_ticket, i);
        temp.detach();
    }
    sleep(5);

    int sum = 0;
    for (int i = 0; i < TICKET_WORK; ++i)
    {
        cout << "窗口" << i << "业绩=" << achievement[i] << endl;
        sum += achievement[i];
    }
    cout << "sum=" << sum << endl;
    mut->lock();
    mut->unlock();
}

volatile int count(0);

mutex mtx;

void add_func()
{
    for (int i = 0; i < 10000; ++i)
    {
        mtx.lock();
        ++count;
        mtx.unlock();
    }
}

void add_func1()
{
    for (int i = 0; i < 10000; ++i)
    {
        if (mtx.try_lock())
        {
            ++count;
            mtx.unlock();
        } else
        {
            cout << "try lock false" << endl;
        }
    }
}

void sync_add_demo()
{
    thread threads[10];
    for (auto & i : threads)
    {
        i = thread(add_func1);
    }
    for (auto &th:threads)
    {
        th.join();
    }
    cout << "count to " << count << " successfully" << endl;
}