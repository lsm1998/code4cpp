/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/31-21:28
* ���ã�
*/
#include "ch09.h"

void ch09()
{
    auto *c=new DeriveCircle();
    c->setColor("��ɫ");
    c->setFilled(true);
    c->setR(2.5);
    c->showInfo();
}