/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/13-0:32
* ���ã�
*/
#include "ch01.h"

/**
 * ��ȡʱ���
 */
void dateDemo()
{
    /**
     * time(0)���ص�ǰʱ���
     */
    time_t t=time(nullptr);
    cout << "��ǰʱ���=" << t << endl;

    // ���ڸ�ʽ��
    static char str_time[100];
    struct tm *local_time = localtime(&t);
    strftime(str_time, sizeof(str_time), "%Y-%m-%d %H:%M:%S", local_time);
    printf ("Time: %s \n", str_time);

    // תʱ���
    struct tm tm=*localtime(&t);
    strftime(str_time, 1000,"%Y-%m-%d %H:%M:%S", &tm);
    time_t ft=mktime(&tm);
    cout << "ʱ���=" << ft << endl;
}