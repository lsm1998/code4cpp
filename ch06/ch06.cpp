/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/24-19:38
* ���ã�
*/
#include <iostream>
#include "ch06.h"

using namespace std;

void freeDemo();

/**
 * C++����֧��Ĭ�ϲ��������ұ�����ĩβλ�ã��ҿ��Զ�����
 * @param args
 */
int default_args(int lastArgs, int args1 = 1, int args2 = 1)
{
    return lastArgs + args1 + args2;
}

void ch06()
{
//    cout << default_args(10) << endl;
//    cout << default_args(10, 5) << endl;
//    cout << default_args(10, 10, 10) << endl;
    point();
    int arr[] = {1, 2, 3};
    arr_point(arr);

    int *a = reverse(arr, 3);
    cout << a << endl;
    delete[] a;
    func_point();

    int i1=1;
    int i2=10;
    // cout << add(&i1,&i2) << endl;

    cout << add(i1,i2) << endl;

    freeDemo();
}

void point()
{
    int p = 10;
    string str = "hello!!!";
    cout << sizeof(p) << endl;
    // boolָ��ֻռ1���ֽڣ�shortָ��ֻռ2���ֽ�
    cout << "boolָ��=" << sizeof(bool) << endl;
    cout << "shortָ��=" << sizeof(short) << endl;
    cout << "intָ��=" << sizeof(int) << endl;
    cout << "longָ��=" << sizeof(long) << endl;
    cout << sizeof(&p) << endl;
    cout << sizeof(str) << endl;
    cout << sizeof(&str) << endl;

    // ����ָ��ָ��һ����������ݵ�ַ���õ�ַʵ�ʵ�ֵ�ǿ��Ըı��
    const int *cp;
    cp = &p;
    cout << "cp=" << *cp << endl;
    p = 20;
    cout << "cp=" << *cp << endl;
}

void arr_point(int *p)
{
    /**
     * C++ָ������ֻ֧�ֹ�ϵ�ͼӼ�����
     * ָ��Ӽ�����ʵ���ǵ�ַƫ�ƣ�ƫ�ƴ�СΪ����=��ֵ*����ռ���ֽ���
     */
    cout << "������Ԫ��=" << *(p + 2) << endl;
    /**
     * C++��������ʵ�ʾ���ָ���һ��Ԫ�صĳ���ָ�룬��ˣ�C++��֧���������¸�ֵ��new�����ĳ���
     */
    int list[] = {1, 2, 3, 4, 5};
    if (list == &list[0])
    {
        cout << "��ַ���," << list << "," << &list[0] << endl;
    }
}

/**
 * ����Ԫ�ط�ת��������������
 * @param arr
 * @param size
 * @return
 */
int *reverse(const int *arr, int size)
{
    // �����ʹ��new����ջ�Ϸ��䣬�ں�������ʱ������
    int *new_arr = new int[size];
    for (int i = 0, j = size - 1; i < size; ++i, j--)
    {
        new_arr[i] = arr[j];
    }
    return new_arr;
}

/**
 * ���������һ��ָ��
 * @param a
 * @param b
 * @return
 */
int (*fp)(int a, int b);

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a > b ? b : a;
}

/**
 * ����ָ�룬һ�������ָ�룬��ָ���������
 * ָ�뺯��������ֵ��ָ�����ͣ�����*reverse����
 */
void func_point()
{
    // ����ָ��fָ�������ֵ�ĺ���max
    fp = max;
    cout << "max=" << (*fp)(1, 2) << endl;
    // ����ָ��fָ������Сֵ�ĺ���min
    fp = min;
    cout << "min=" << (*fp)(1, 2) << endl;
}


/**
 * ����2�������������Ͳ�һ�£���Ч����һ����
 * int * ���������ָ�����
 * int & ���������ֵ���󣬵�ʵ�ʴ��ݵ�Ҳ��ָ��
 */


int add(int *a,int *b)
{
    // *a++ �� *a+=1 �����һ�£�
    // ��Ҫʹ��(*a)++
    (*a)++;
    *b+=2;
    return *a+*b;
}

int add(int &a,int &b)
{
    a++;
    b+=2;
    return a+b;
}