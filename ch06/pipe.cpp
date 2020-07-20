/*
* 作者：刘时明
* 时间：2020/7/16 0016-0:12
* 作用：
*/
#include <sys/wait.h>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <sys/sem.h>
#include <sys/msg.h>
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

void sem_demo()
{
    key_t sem_key;
    if ((sem_key = ftok("./Makefile", 123)) < 0)
    {
        cout << "ftok failed" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "ftok ok,sem_key=" << sem_key << endl;
}

struct my_msg_st
{
    long int my_msg_type;
    // BUFSIZ = 1024 * 8
    char some_text[BUFSIZ];
};

void msg_stat(int id, msqid_ds ds);

void msg_receive_demo()
{
    int running = 1;
    int msg_id;
    struct my_msg_st some_data{};
    long int msg_to_receive = 0;
    msg_id = msgget((key_t) 123, 0666 | IPC_CREAT);
    if (msg_id == -1)
    {
        fprintf(stderr, "msgget error\n");
        exit(EXIT_FAILURE);
    }
    printf("开始接受消息\n");
    while (running)
    {
        if (msgrcv(msg_id, (void *) &some_data, BUFSIZ, msg_to_receive, 0) == -1)
        {
            exit(EXIT_FAILURE);
        }
        cout << "you wrote:" << some_data.some_text << endl;
        if (strncmp(some_data.some_text, "end", 3) == 0)
        {
            running = 0;
        }
    }
    if (msgctl(msg_id, IPC_RMID, nullptr) == -1)
    {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

#define MAX_TEXT 512

void msg_send_demo()
{
    int running = 1;
    int msg_id;
    struct my_msg_st some_data{};
    char buffer[BUFSIZ];

    msg_id = msgget((key_t) 123, 0666 | IPC_CREAT);
    if (msg_id == -1)
    {
        fprintf(stderr, "msgget error\n");
        exit(EXIT_FAILURE);
    }
    while (running)
    {
        cout << "输入：";
        fgets(buffer, BUFSIZ, stdin);
        some_data.my_msg_type = 1;
        strcpy(some_data.some_text, buffer);
        if (msgsnd(msg_id, (void *) &some_data, MAX_TEXT, 0) == -1)
        {
            fprintf(stderr, "msg send error\n");
            exit(EXIT_FAILURE);
        }
        if (strncmp(some_data.some_text, "end", 3) == 0)
        {
            running = 0;
        }
    }
    cout << "正常退出" << endl;
    exit(EXIT_SUCCESS);
}

void msg_stat_demo()
{
    int g_flags, s_flags, r_flags;
    key_t key;
    int msg_id;
    int re_val;
    struct msg_s_buf
    {
        int m_type;
        char m_text[1];
    } msg_s_buf{};

    struct msg_m_buf
    {
        int m_type;
        char m_text[10];
    } msg_r_buf{};

    struct msqid_ds msg_g_info{}, msg_s_info{};
    char msg_path[] = "./Makefile";
    key = ftok(msg_path, 'b');
    g_flags = IPC_CREAT | IPC_EXCL;
    msg_id = msgget(key, g_flags | 0666);
    if (msg_id == -1)
    {
        cout << "msg create error" << endl;
    }
    msg_stat(msg_id, msg_g_info);

    s_flags = IPC_NOWAIT;
    msg_s_buf.m_type = 10;
    msg_s_buf.m_text[0] = 'a';
    re_val = msgsnd(msg_id, &msg_s_buf, sizeof(msg_s_buf.m_text), s_flags);
    if (re_val == -1)
    {
        cout << "message send error" << endl;
    }
    msg_stat(msg_id, msg_g_info);

    re_val = msgctl(msg_id, IPC_RMID, nullptr);
    if (re_val == -1)
    {
        cout << "unlike msg queue error" << endl;
    }
}

void msg_stat(int msg_id, msqid_ds msg_info)
{
    int re_val;
    sleep(1);
    re_val = msgctl(msg_id, IPC_STAT, &msg_info);
    if (re_val == -1)
    {
        printf("get msg info error\n");
    }
    cout << msg_info.msg_qbytes << endl;

    cout << msg_info.msg_ctime << endl;

    cout << msg_info.msg_rtime << endl;
}
