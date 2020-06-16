/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/11-0:04
* ���ã������
*/
#include "ch02.h"

void tcpSocketServer()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // ����socket
    SOCKET severSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    // ָ��IP�Ͷ˿�
    struct sockaddr_in ServerAddr{};
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    ServerAddr.sin_port = htons(8848);

    // socket��IP�˿�
    bind(severSocket, (SOCKADDR *) &ServerAddr, sizeof(ServerAddr));

    // �˿ڼ���
    listen(severSocket, SOMAXCONN);

    sockaddr_in ClientAddr{};
    int size = sizeof(ClientAddr);

    printf("��ʼ����... \n");
    SOCKET clientSocket = accept(severSocket, (SOCKADDR *) &ClientAddr, &size);
    printf("һ���ͻ������ӣ�IP=%s,port=%d \n", inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));

    // ������Ϣ
    char msg[MAXBYTE] = {0};
    lstrcpy(msg, "hello client!\r\n");
    send(clientSocket, msg, strlen(msg) + sizeof(char), 0);

    // ������Ϣ
    recv(clientSocket, msg, MAXBYTE, 0);
    printf("client => %s \n", msg);

    WSACleanup();
}