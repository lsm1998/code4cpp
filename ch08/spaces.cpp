/*
* ���ߣ���ʱ��
* ʱ�䣺2020/7/5 0005-23:20
* ���ã�
*/
#include "ch08.h"

namespace my_spaces
{
    int number;

    class Animal
    {
    public:
        string name;
    };
}

void spaces_demo()
{
    my_spaces::number = 100;

    my_spaces::Animal dog{};
    dog.name = "��";

    cout << my_spaces::number << endl;
    cout << dog.name << endl;
}