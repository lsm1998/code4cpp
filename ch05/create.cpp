/*
* 作者：刘时明
* 时间：2020/7/8 0008-23:11
* 作用：
*/
#include "ch05.h"
#include <unistd.h>

void fork_demo()
{
    pid_t fPid;
    int count = 0;
    fPid = fork();
    if (fPid < 0)
    {
        cout << "创建失败" << endl;
    } else if (fPid == 0)
    {
        // 返回0则进入子程序执行
        cout << "进入子程序" << endl;
        cout << "我是子程序，pid=" << getpid() << endl;
        count++;
    } else
    {
        cout << "依旧执行父进程" << endl;
        cout << "我是父程序，pid=" << getpid() << endl;
        count++;
    }
    cout << "result=" << count << endl;
    // 等待一会儿
    sleep(50);
}