/*
* 作者：刘时明
* 时间：2020/6/11-0:04
* 作用：服务端
*/
#include "ch02.h"

void tcpSocketServer()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 创建socket
    SOCKET severSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 指定IP和端口
    struct sockaddr_in ServerAddr{};
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    ServerAddr.sin_port = htons(8848);

    // socket绑定IP端口
    bind(severSocket, (SOCKADDR *) &ServerAddr, sizeof(ServerAddr));

    // 端口监听
    listen(severSocket, SOMAXCONN);

    sockaddr_in ClientAddr{};
    int size = sizeof(ClientAddr);

    printf("开始监听... \n");
    SOCKET clientSocket = accept(severSocket, (SOCKADDR *) &ClientAddr, &size);
    printf("一个客户端连接，IP=%s,port=%d \n", inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));

    // 发送消息
    char msg[MAXBYTE] = {0};
    lstrcpy(msg, "hello client!\r\n");
    send(clientSocket, msg, strlen(msg) + sizeof(char), 0);

    // 接收消息
    recv(clientSocket, msg, MAXBYTE, 0);
    printf("client => %s \n", msg);

    WSACleanup();
}