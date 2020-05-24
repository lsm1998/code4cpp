/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/24-20:27
* ���ã�
*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "thread.h"

using namespace std;

// http://blog.chinaunix.net/uid-26275986-id-3886498.html
/**
 * windows�����߳� CreateThread()
 * ����1����ȫ���Խṹ����Ҫ���Ƹ��߳̾���Ƿ��Ϊ���̵��ӽ��̼̳�ʹ�ã�Ĭ��ʹ��NULLʱ��ʾ���ܼ̳У�����̳��߳̾��������Ҫ���øýṹ�壬���ṹ���bInheritHandle��Ա��ʼ��ΪTRUE��
 * ����2���̳߳�ʼջ�Ĵ�С����ʹ��0���ʾ����Ĭ�ϴ�С��ʼ����
 * ����3���߳̿�ʼ��λ�ã����߳�Ҫִ�еĺ������룻
 * ����4�������̹߳��̺����Ĳ���������Ҫʱ��������ΪNULL��
 * ����5�������߳�ʱ�ı�־��CREATE_SUSPENDED��ʾ�̴߳���������ݲ�ִ�У��������ResumeThread�ſ���ִ�У�0��ʾ�̴߳���֮������ִ�У�
 * ����6�������̵߳�ID��
 * @return
 */
int thread()
{
    int j = 0;
    HANDLE hThread_1 = CreateThread(NULL, 0, theadFunc, NULL, 0, NULL);
    CloseHandle(hThread_1);
    while (j++ < 1000)
    {
        printf("MainThread run once count=%d\n", j);
    }
    system("pause");
    return 0;
}

/**
 * ������Java��run����
 * @param lpParameter
 * @return
 */
DWORD WINAPI theadFunc(LPVOID lpParameter)
{
    int i = 0;
    while (i++ < 1000)
    {
        printf("DeputyThread run once count=%d\n", i);
    }
    return 0;
}
