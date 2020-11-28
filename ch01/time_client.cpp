//
// Created by 刘时明 on 2020/11/28.
//

#include <common.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    int sock_fd, n;
    char buff[MAX_LEN + 1];
    struct sockaddr_in serv_addr{};

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        panic("socket error!")
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(13);

    if (connect(sock_fd, (struct sockaddr *) (&serv_addr), sizeof(serv_addr)) < 0)
    {
        panic("connect error!")
    }
    while ((n = read(sock_fd, buff, MAX_LEN)) > 0)
    {
        buff[n] = 0;
        if (fputs(buff, stdout) == EOF)
        {
            panic("fputs error!")
        }
    }
    if (n < 0)
    {
        panic("read error!")
    }
    return 0;
}