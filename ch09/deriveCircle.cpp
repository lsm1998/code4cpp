/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/31-21:45
* ���ã�
*/
#include "deriveCircle.h"

const double &DeriveCircle::area() const
{
    double area=r * r * PI;
    double *result=&area;
    return *result;
}

double DeriveCircle::getR() const
{
    return r;
}

void DeriveCircle::setR(double r)
{
    DeriveCircle::r = r;
}

void DeriveCircle::showInfo() const
{
    cout << "Բ" << endl;
    cout << "color=" << this->getColor() << endl;
    cout << "filled=" << this->isFilled() << endl;
    cout << "���=" << this-> area() << endl;
}
