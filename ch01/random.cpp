/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/13-0:51
* ���ã�
*/
#include "ch01.h"

/**
 * �������
 */
void random()
{
    /**
     * rand()����һ���������
     * srand(int)�����޸�������������ӣ�����Ĭ��Ϊ1
     */
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i)
    {
        printf("��%d��ѭ�������ֵ=%d\n", i + 1, rand());
    }
}