/*
* 作者：刘时明
* 时间：2020/7/8 0008-22:13
* 作用：
*/
#include "ch05.h"
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>
#include <csignal>

bool check_pid(char *pid_file);

static char *start_pid_file_default = (char *) "/var/run/test.pid";

void pid_demo()
{
    pid_t pid;
    // 64位系统pid为4字节
    cout << "pid bytes=" << sizeof(pid) << endl;

    pid = getpid();

    cout << "当前进程pid=" << pid << endl;


    FILE *fd = fopen(start_pid_file_default, "w");
    if (fd)
    {
        fprintf(fd, "%u\n", getpid());
        fclose(fd);
    }
    if (check_pid(start_pid_file_default))
    {
        printf("test is already running (%s exists)", start_pid_file_default);
    } else
    {
        printf("test is not running (%s exists)", start_pid_file_default);
    }
    sleep(20);
    // unlink删除文件
    unlink(start_pid_file_default);
}

bool check_pid(char *pid_file)
{
    struct stat stb{};
    FILE *file;
    if (stat(pid_file, &stb) == 0)
    {
        file = fopen(pid_file, "r");
        if (file)
        {
            char buf[64];
            pid_t pid = 0;
            memset(buf, 0, sizeof(buf));
            if (fread(buf, 1, sizeof(buf), file))
            {
                buf[sizeof(buf) - 1] = '\0';
                pid = atoi(buf);
            }
            fclose(file);
            if (pid && kill(pid, 0) == 0)
            {
                return true;
            }
        }
        printf("删除 pidFile '%s'，进程没有在运行", pid_file);
        unlink(pid_file);
    }
    return false;
}