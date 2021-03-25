//
// Created by 刘时明 on 2020/12/13.
//
#include <unistd.h>
#include <iostream>

using namespace std;

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

void exec_demo()
{
    // 使用execl执行程序
    execl("/bin/pwd", "", nullptr);
    // 使用execl执行带参数程序
    execl("/bin/ls", "ls", "-al", "/etc/passwd", nullptr);
}

int system_demo(const char *cmdString)
{
    // 1127475986
    pid_t pid;
    int status;
    if (cmdString == nullptr)
    {
        return 1;
    }
    if ((pid = fork()) < 0)
    {
        status = -1;
    } else if (pid == 0)
    {
        execl("/bin/sh", "sh", "-c", cmdString, nullptr);
        _exit(127);
    } else
    {
        while (waitpid(pid, &status, 0) < 0)
        {
            if (errno != EINTR)
            {
                status = -1;
                break;
            }
        }
    }
    return status;
}

void pr_exit(int status)
{
    // 是否正常终止子进程返回的状态
    if (WIFEXITED(status))
    {
        printf("normal termination,exit status=%d \n", WEXITSTATUS(status));
        // 是否异常终止子进程返回的状态
    } else if (WIFSIGNALED(status))
    {
        printf("normal termination,signal number=%d%s \n", WTERMSIG(status),
#ifdef WCOREDUMP
               WCOREDUMP(status) ? "(core file generated)" : "");
#else
        "");
#endif
    // 是否当前暂停子进程返回的状态
    }else if(WIFSTOPPED(status))
    {
        printf("child stopped,signal number=%d \n", WSTOPSIG(status));
    }
}