//
// Created by 刘时明 on 2020/12/5.
//
#include <sys/wait.h>
#include <cstdio>
#include <cstring>
#include <zconf.h>
#include <cstdlib>

#define MAX_LEN 4*1024

void shell()
{
    char buf[MAX_LEN];
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(buf, MAX_LEN, stdin) != nullptr)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;
            if ((pid = fork()) < 0)
            {
                printf("fork error!");
                exit(0);
            } else if (pid == 0)
            {
                execlp(buf, buf, (char *) nullptr);
                printf("子进程，%s \n", buf);
                exit(127);
            } else
            {
                // 等待子进程结束
                if (pid == waitpid(pid, &status, 0) < 0)
                {
                    printf("waitpid error \n");
                }
                printf("%% ");
            }
        }
    }
}
