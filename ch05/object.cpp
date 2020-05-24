/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/24-17:16
* ���ã�
*/
#include "object.h"
#include <iostream>

using namespace std;

void Student::show()
{
    cout << "ID=" << ID << endl;
    cout << "CODE=" << CODE << endl;
    cout << "����=" << name << endl;
    cout << "�Ա�=" << (gender == Men ? "��" : gender == WoMen ? "Ů" : nullptr) << endl;
}

Student::Student(string name, Gender gender)
{
    this->gender = gender;
    this->name = move(name);
}

const string &Student::getName() const
{
    return name;
}

void Student::setName(const string &name)
{
    Student::name = name;
}
