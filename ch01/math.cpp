/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/13-0:55
* ���ã�
*/
#include "ch01.h"

/**
 * ������ѧ����
 */
void math_demo()
{
    printf("%lf\n", sqrt(PI));

    printf("%lf\n", sin(PI));
    printf("%lf\n", cos(PI));

    cout << "Բ����=" << M_PI << endl;

    cout << "����ȡ��=" << ceil(PI) << endl;
    cout << "����ȡ��=" << floor(PI) << endl;

    double ma = max(PI, M_E);
    double mi = min(PI, M_E);
    cout << "���ֵ=" << ma << endl;
    cout << "��Сֵ=" << mi << endl;
}

