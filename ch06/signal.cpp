/*
* 作者：刘时明
* 时间：2020/7/15 0015-23:06
* 作用：信号
*/
#include "ch06.h"
#include <unistd.h>
#include <wait.h>

void signal_demo()
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
        puts("in child process");
        sleep(100);
        exit(EXIT_SUCCESS);
    } else
    {
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
                printf("%d killed\n",childPid);
            }
        }
    }
    exit(EXIT_SUCCESS);
}