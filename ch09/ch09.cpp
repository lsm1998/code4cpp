/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/31-21:28
* ���ã�
*/
#include "ch09.h"

void cast1(GeometricObj &obj);

GeometricObj& cast2(DeriveCircle &circle);

void ch09()
{
    auto *c=new DeriveCircle();
    c->setColor("��ɫ");
    c->setFilled(true);
    c->setR(2.5);
    c->showInfo();

    // ���д��麯�������ǳ����࣬�����Ա�ʵ����

    // auto *g=new GeometricObj();
    cast1(*c);

    c->setR(100);
    cast2(*c).showInfo();
}

/**
 * ����ת��
 * dynamic_castֻ���ڶ�̬���͵�ָ�����������ʹ�ã�Ҳ���Ǳ���������麯��
 * static_cast������ʱ�������ת���Ƿ�ɹ��������ڱ���ʱ
 * @param obj
 */
void cast1(GeometricObj &obj)
{
    cout << "cast" << endl;
    obj.showInfo();
    auto cast=dynamic_cast<DeriveCircle&>(obj);
    cout << "r="<< cast.getR() << endl;
}

GeometricObj& cast2(DeriveCircle &circle)
{
    return circle;
}