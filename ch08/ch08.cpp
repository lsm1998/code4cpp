/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/31-0:14
* ���ã�
*/
#include "ch08.h"

template<class T>
void hello(T value);

void ch08()
{
    hello("123");

    hello(123);

    hello(3.14F);

    hello('1');
}

/**
 * ��ȡģ���������ʱ����
 * @tparam T
 * @param value
 */
template<class T>
void hello(T value)
{
    cout << typeid(T).name() << ":" << value << endl;
}