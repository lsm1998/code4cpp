//
// Created by lsm on 2021/3/9.
//
#include "main.h"

int main(int argc, char *argv[])
{
    int sock_fd, num;
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in server{};

    if ((he = gethostbyname(IP)) == nullptr)
    {
        cout << "gethostbyname() error " << endl;
        exit(1);
    }

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        cout << "socket() error " << endl;
        exit(1);
    }
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *((struct in_addr *) he->h_addr);
    if (connect(sock_fd, (struct sockaddr *) &server, sizeof(server)) == -1)
    {
        cout << "connect() error " << endl;
        exit(1);
    }
    string str{};

    while (true)
    {
        cout << "input msg:" << endl;
        cin >> str;
        if (str == "exit")
        {
            break;
        }
        if ((num = send(sock_fd, str.c_str(), sizeof(str), 0)) == -1)
        {
            cout << "send() error " << endl;
            exit(1);
        }
        cout << "send bytes len is:" << num << endl;
        if ((num = recv(sock_fd, buf, MAXDATASIZE, 0)) == -1)
        {
            cout << "recv() error " << endl;
            exit(1);
        }
        buf[num - 1] = '\0';
        cout << "server message:" << buf << endl;
        cout << "---" << "recv bytes len is:" << num << "---" << endl;
    }
    close(sock_fd);
    return 0;
}