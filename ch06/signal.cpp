/*
* 作者：刘时明
* 时间：2020/7/15 0015-23:06
* 作用：信号
*/
#include "ch06.h"
#include <csignal>
#include <unistd.h>
#include <wait.h>

void sig_usr(int sig_num)
{
    if (sig_num == SIGUSR1)
    {
        printf("SIGUSR1 received \n");
    } else if (sig_num == SIGUSR2)
    {
        printf("SIGUSR2 received \n");
    } else if (sig_num == SIGHUP)
    {
        printf("SIGHUP在此！\n");
    } else
    {
        printf("signal %d received \n", sig_num);
    }
}

void sig_handler(int sig)
{
    cout << "Deal SIGINT" << endl;
}

/**
 * 使用kill发送信号终止目标进程
 */
void signal_kill_demo()
{
    cout << "hello world!!!" << endl;

    pid_t childPid;
    int status;
    int retVal;

    childPid = fork();

    if (-1 == childPid)
    {
        perror("fork()");
        exit(EXIT_FAILURE);
    } else if (0 == childPid)
    {
        // puts就是没有格式转换功能的printf
        puts("in child process");
        sleep(100);
        exit(EXIT_SUCCESS);
    } else
    {
        sleep(5);
        if (0 == (waitpid(childPid, &status, WNOHANG)))
        {
            // 使用kill向一个进程或进程组发送信号
            retVal = kill(childPid, SIGKILL);
            if (retVal)
            {
                puts("kill failed.");
                perror("kill");
                waitpid(childPid, &status, 0);
            } else
            {
                printf("%d killed\n", childPid);
            }
        }
    }
    exit(EXIT_SUCCESS);
}

/**
 * 使用sigaction设置信号处理方式
 */
void signal_sigaction_demo()
{
    char buf[512];
    int n;
    struct sigaction sa{};
    sa.sa_flags = 0;
    sa.sa_handler = sig_usr;
    sigaction(SIGUSR1, &sa, nullptr);
    sigaction(SIGUSR2, &sa, nullptr);
    sigaction(SIGHUP, &sa, nullptr);
    cout << "我的进程ID=" << getpid() << endl;
    const int count = 10;
    for (int i = 0; i < count; ++i)
    {
        cout << "正在接受第" << (i + 1) << "/" << count << "条信号" << endl;
        if ((n = read(STDIN_FILENO, buf, 511)) == -1)
        {
            if (errno == EINTR)
            {
                cout << "read is interrupted by signal" << endl;
            }
        } else
        {
            buf[n] = '\0';
            cout << n << " bytes read:" << buf << endl;
        }
    }
}

/**
 * 使用sigrocmask检测和更改信号屏蔽字
 */
void signal_proc_mask_demo()
{
    sigset_t new_mask;
    sigset_t old_mask;
    sigset_t pend_mask;
    struct sigaction act{};
    act.sa_handler = sig_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, nullptr);
    sigemptyset(&new_mask);
    sigaddset(&new_mask, SIGINT);
    sigprocmask(SIG_BLOCK, &new_mask, &old_mask);
    sleep(5);
    sigpending(&pend_mask);
    if (sigismember(&pend_mask, SIGINT))
    {
        cout << "悬而未决，命令已收到，暂不处理" << endl;
    }
    sigprocmask(SIG_SETMASK, &old_mask, nullptr);
    cout << "SIGINT unblocked，开始处理" << endl;
    sleep(10);
    cout << "正常退出" << endl;
}

void handler_fun(int sig)
{
    cout << "catch signal " << sig << endl;
}

/**
 * 使用signal自定义信号处理
 */
[[noreturn]] void signal_handler_fun()
{
    cout << "pid=" << getpid() << endl;
    signal(SIGINT, handler_fun);
    while (true)
    {};
}