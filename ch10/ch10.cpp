/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/1-23:09
* ���ã�
*/
#include "ch10.h"

void ch10()
{
    int num;
    cout << "����һ������" << endl;
    cin>> num;
    int a;
    try
    {
        if(num==0)
        {
            throw 0;
        }
        a = 1 / num;
    } catch (int ex)
    {
        cout << "ex=" << ex<<endl;
    }
    cout << "a=" << a <<endl;
}