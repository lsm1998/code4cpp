//
// Created by 刘时明 on 2020/11/28.
//
#include <ctime>
#include <unistd.h>
#include <common.h>
#include <netinet/in.h>

int main()
{
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr{};
    char buff[MAX_LEN];
    time_t ticks;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0)
    {
        panic("socket error!")
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(13);
    if (bind(listen_fd, (struct sockaddr *) (&serv_addr), sizeof(struct sockaddr)) < 0)
    {
        panic("bind error!")
    }
    if (listen(listen_fd, 5) < 0)
    {
        panic("listen error!")
    }

    for (;;)
    {
        conn_fd = accept(listen_fd, nullptr, nullptr);
        printf("一个连接进入!\n");
        if (conn_fd < 0)
        {
            panic("accept error!")
        }
        ticks = time(nullptr);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(conn_fd, buff, strlen(buff));
        close(conn_fd);
    }
    return 0;
}