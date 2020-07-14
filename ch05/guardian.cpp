/*
* 作者：刘时明
* 时间：2020/7/14 0014-23:03
* 作用：守护进程
*/
#include <csignal>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ch05.h"

#define MAX_FILE 65535

volatile sig_atomic_t running = 1;

void sigterm_handler(int args)
{
    running = 0;
}

void guardian()
{
    pid_t pc;
    int i, fd, len;
    char *buf = (char *) "this is a demo\n";
    len = strlen(buf);
    pc = fork();
    if (pc < 0)
    {
        cout << "fork失败！" << endl;
        exit(1);
    } else if (pc > 0)
    {
        exit(0);
    }
    setsid();
    chdir("/");
    umask(0);
    for (int j = 0; j < MAX_FILE; ++j)
    {
        close(j);
    }
    signal(SIGTERM, sigterm_handler);
    while (running)
    {
        if ((fd = open("/tmp/dameon.log", O_CREAT | O_WRONLY | O_APPEND, 0600)) < 0)
        {
            perror("open");
            exit(1);
        }
        write(fd, buf, len + 1);
        close(fd);
        // 10毫秒
        usleep(10 * 1000);
    }
}