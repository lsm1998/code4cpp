/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/23-0:08
* ���ã�
*/
#include "ch01.h"

void readStdInput1();

void readStdInput2();

void readStdInput3();

void readLine();

void dateDemo();

void random();

void math_demo();

void char_demo();

void string_demo();

/**
 * ��ͨ��������
 */
inline void inline_func1()
{
    cout << "����һ����������" << endl;
}

/**
 * ��ͨ��������
 */
inline int inline_func2(int number)
{
    cout << "����һ����������" << endl;
    return number % 2;
}

/**
 * �ṹ����������
 */
struct InLineDemo
{
private:
    int number;

public:
    inline void inline_func()
    {
        cout << this->number++ << endl;
        cout << "����һ����������" << endl;
    }
};

void ch01()
{
    // readStdInput3();
    // char_arr_string();

//    inline_func1();
//    cout << inline_func2(1) << endl;
//    InLineDemo demo{};
//    demo.inline_func();
//
//    char_arr_string();
//
//    readLine();

    string_base_opt();
}