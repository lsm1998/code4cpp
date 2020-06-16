/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/11-0:04
* ���ã��ͻ���
*/
#include "ch02.h"

void tcpSocketClient()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // ����socket
    SOCKET clientSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    // ָ��IP�Ͷ˿�
    struct sockaddr_in ServerAddr{};
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    ServerAddr.sin_port = htons(8848);

    // ���ӷ�����
    connect(clientSocket, (SOCKADDR *) &ServerAddr, sizeof(ServerAddr));

    char msg[MAXBYTE] = {0};
    // ������Ϣ
    recv(clientSocket, msg, MAXBYTE, 0);
    printf("server => %s \n", msg);

    // ������Ϣ
    lstrcpy(msg, "hello server!\r\n");
    send(clientSocket, msg, strlen(msg) + sizeof(char), 0);

    WSACleanup();
}