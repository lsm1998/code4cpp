#include "ch03.h"
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>

/*
* 作者：刘时明
* 时间：2020/7/24 0024-22:43
* 作用：
*/

void tcp_server()
{
    int sfp, nfp;
    struct sockaddr_in s_add{}, c_add{};
    socklen_t sin_size;
    unsigned short port = 10051;
    cout << "服务端准备就绪" << endl;
    sfp = socket(AF_INET, SOCK_STREAM, 0);
    if (sfp == -1)
    {
        cout << "socket fail!" << endl;
        return;
    }
    int on = 1;
    setsockopt(sfp, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    bzero(&s_add, sizeof(struct sockaddr_in));
    s_add.sin_family = AF_INET;
    s_add.sin_addr.s_addr = htonl(INADDR_ANY);
    s_add.sin_port = htons(port);
    bind(sfp, (struct sockaddr *) (&s_add), sizeof(struct sockaddr));
    if (listen(sfp, 5) == -1)
    {
        cout << "listen fail!" << endl;
        return;
    }

    while (true)
    {
        sin_size = sizeof(struct sockaddr_in);
        nfp = accept(sfp, (struct sockaddr *) (&c_add), &sin_size);
        if (nfp == -1)
        {
            cout << "accept fail!" << endl;
            break;
        }
        cout << "一个客户端连入，ip=" << inet_ntoa(c_add.sin_addr) << ",port=" << ntohs(c_add.sin_port) << endl;
        if (write(nfp, "你好客户端，欢迎连接! \r\n", 32) == -1)
        {
            cout << "write fail!" << endl;
            return;
        }
        close(nfp);
        puts("输入y退出 ");
        char ch[2];
        scanf("%s", ch);
        if (ch[0] == 'y')
        {
            break;
        }
    }
    close(sfp);
    cout << "服务端退出" << endl;
}