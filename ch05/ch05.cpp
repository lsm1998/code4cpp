/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/24-17:13
* ���ã�
*/
#include "ch05.h"
#include "stack.h"
#include <iostream>

using namespace std;

string Student::ID = "431224";
int Student::CODE = 1998;

void ch05()
{
    auto *student = new Student("��ʱ��", Men);
    student->show();

    auto *stack = new Stack();
    for (int i = 0; i < 5; ++i)
    {
        stack->push(i * 10);
    }
    cout << stack->peek() << endl;
    cout << stack->get_size() << endl;

    while (!stack->is_empty())
    {
        cout << "����һ��=" << stack->pop() << endl;
    }
}