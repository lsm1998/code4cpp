//
// Created by lsm on 2021/3/9.
//
#include "main.h"

#define MAX_LEN 1024
#define SERV_PORT 8000
#define MAX_OPEN_FD 1024

int main(int argc, char *argv[])
{
    int listen_fd, conn_fd, efd, ret;
    char buf[MAX_LEN];
    struct sockaddr_in cli_addr{}, serv_addr{};
    socklen_t client = sizeof(cli_addr);
    struct epoll_event tep{}, ep[MAX_OPEN_FD];

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SERV_PORT);
    bind(listen_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    listen(listen_fd, 20);
    // 创建一个epoll fd
    efd = epoll_create(MAX_OPEN_FD);
    tep.events = EPOLLIN;
    tep.data.fd = listen_fd;
    // 把监听socket 先添加到efd中
    ret = epoll_ctl(efd, EPOLL_CTL_ADD, listen_fd, &tep);
    printf("epoll ctl,ret=%d\n",ret);
    // 循环等待
    while (true)
    {
        // 返回已就绪的epoll_event,-1表示阻塞,没有就绪的epoll_event,将一直等待
        size_t n_ready = epoll_wait(efd, ep, MAX_OPEN_FD, -1);
        if(n_ready<0)
        {
            break;
        }
        for (int i = 0; i < n_ready; ++i)
        {
            // 如果是新的连接,需要把新的socket添加到efd中
            if (ep[i].data.fd == listen_fd)
            {
                conn_fd = accept(listen_fd, (struct sockaddr *) &cli_addr, &client);
                tep.events = EPOLLIN;
                tep.data.fd = conn_fd;
                ret = epoll_ctl(efd, EPOLL_CTL_ADD, conn_fd, &tep);
                printf("join conn,ret=%d \n",ret);
            }
            // 否则,读取数据
            else
            {
                conn_fd = ep[i].data.fd;
                int bytes = read(conn_fd, buf, MAX_LEN);
                // 客户端关闭连接
                if (bytes == 0)
                {
                    ret = epoll_ctl(efd, EPOLL_CTL_DEL, conn_fd, NULL);
                    close(conn_fd);
                    printf("client[%d] closed , ret=%d \n", i,ret);
                } else
                {
                    for (int j = 0; j < bytes; ++j)
                    {
                        buf[j] = toupper(buf[j]);
                    }
                    // 向客户端发送数据
                    write(conn_fd, buf, bytes);
                }
            }
        }
    }
    return 0;
}
