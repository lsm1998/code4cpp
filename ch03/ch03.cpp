#include <thread>
#include <unistd.h>
#include "ch03.h"

void ip_demo();

void tcp_client();

void tcp_server();

void ch03()
{
    ip_demo();

    thread server(tcp_server);
    thread client(tcp_client);
    server.detach();
    sleep(1);
    client.detach();
    sleep(60);
}