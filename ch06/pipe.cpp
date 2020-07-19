/*
* 作者：刘时明
* 时间：2020/7/16 0016-0:12
* 作用：
*/
#include <sys/wait.h>
#include <cstring>
#include <unistd.h>
#include "ch06.h"

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}

void pipe_demo()
{
    pid_t pid;
    char buf[1024];
    int fd[2];
    char *p = (char *) "test for pipe\n";
    if (pipe(fd) == -1)
    {
        sys_err("pipe err");
    }
    pid = fork();
    if (pid < 0)
    {
        sys_err("fork err");
    } else if (pid == 0)
    {
        // 子进程读数据
        close(fd[1]);
        cout << "子进程等待读数据" << endl;
        // 等待管道上的数据
        int len = read(fd[0], buf, sizeof(buf));
        write(STDOUT_FILENO, buf, len);
        close(fd[0]);
    } else
    {
        close(fd[0]);
        write(fd[1], p, strlen(p));
        wait(nullptr);
        close(fd[1]);
    }
}