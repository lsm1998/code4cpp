/*
* ���ߣ���ʱ��
* ʱ�䣺2020/7/15 0015-0:15
* ���ã�����ͨ��
*/
#include <thread>
#include <unistd.h>
#include "ch06.h"

void signal_kill_demo();

void signal_sigaction_demo();

void signal_proc_mask_demo();

void signal_handler_fun();

void pipe_demo();

void sem_demo();

void msg_receive_demo();

void msg_send_demo();

void ch06()
{
    // signal_kill_demo();

    // signal_sigaction_demo();

    // signal_proc_mask_demo();

    // signal_handler_fun();

    // pipe_demo();

    sem_demo();




    thread receive(msg_receive_demo);
    thread send(msg_send_demo);
    receive.detach();
    send.detach();
    sleep(60);
}
