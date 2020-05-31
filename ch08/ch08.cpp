/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/31-0:14
* ���ã�
*/
#include <string>
#include <iostream>
#include "ch08.h"

using namespace std;

void string_operator();

void rational();

void ch08()
{
    string_operator();

    rational();
}

/**
 * string���� <��>��+��[]�����������ͨ��operator�ؼ������
 */
void string_operator()
{
    string s1("�ϰ�");
    string s2("hello");
    cout << "first=" << s2[0] << endl;
    cout << "first=" << s2.operator[](0) << endl;
    s1.operator+=(s2);
    cout << s1 << endl;
}

void rational()
{
    auto *r1 = new Rational(1, 2);
    auto *r2 = new Rational(1, 2);
    auto r3 = *r1 + *r2;
    cout << r3.toString() << endl;
    cout << (r1 < &r3) << endl;

    cout << r3[0] << "," << r3[1] << endl;

    // ͨ����Ԫ�����ı�˽������
    change(r3, 7, 8);
    cout << r3[0] << "," << r3[1] << endl;

    // ����Զ�����ת��
    int intVal = r3;
    cout << "intVal=" << intVal << endl;

    auto r4 = r3;
    cout << "eq? " << r4.equals(r3) << endl;
    printf("%p , %p \n", r3, r4);
}