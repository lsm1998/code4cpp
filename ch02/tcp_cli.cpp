/*
* 作者：刘时明
* 时间：2020/6/11-0:04
* 作用：客户端
*/
#include "ch02.h"

void tcpSocketClient()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 创建socket
    SOCKET clientSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 指定IP和端口
    struct sockaddr_in ServerAddr{};
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    ServerAddr.sin_port = htons(8848);

    // 连接服务器
    connect(clientSocket, (SOCKADDR *) &ServerAddr, sizeof(ServerAddr));

    char msg[MAXBYTE] = {0};
    // 接收消息
    recv(clientSocket, msg, MAXBYTE, 0);
    printf("server => %s \n", msg);

    // 发送消息
    lstrcpy(msg, "hello server!\r\n");
    send(clientSocket, msg, strlen(msg) + sizeof(char), 0);

    WSACleanup();
}