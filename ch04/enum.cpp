/*
* ���ߣ���ʱ��
* ʱ�䣺2020/7/5 0005-10:04
* ���ã�
*/
#include "ch04.h"

enum Color
{
    RED, BLACK
};

string get_color(Color c);


void enum_demo()
{
    Color c{RED};

    cout << get_color(c) << endl;
    cout << get_color(BLACK) << endl;
}

inline string get_color(Color c)
{
    if (c == RED)
    {
        return "��ɫ";
    } else if (c == BLACK)
    {
        return "��ɫ";
    } else
    {
        return "����ʶ��";
    }
}