/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/13-0:28
* ���ã���ȡ��������
*/
#include "ch01.h"

void readStdInput1()
{
    /**
     * C++�У�cin��ʾ��׼����̨����
     * >> Ϊ����ȡ����
     */
    double radius = 0;
    cout << "����뾶��";
    cin >> radius;
    double area = radius * radius * PI;
    cout << "Բ�����=" << area << endl;
    cout << "double���ͳ���Ϊ��" << sizeof(area) << "byte" << endl;
}

void readStdInput2()
{
    /**
     * C++�У�double number1(0)�ȼ���double number=0
     */
    double number1(0), number2(0), number3(0);
    cout << "����������ֵ��";
    cin >> number1 >> number2 >> number3;
    cout << "ƽ��ֵ=" << (number1 + number2 + number3) / 3;
}

void readStdInput3()
{
    char c[1];
    scanf("%s", &c);
    cout << "��������ǣ�" << c << endl;
}

void readLine()
{
    // ��ȡһ�У��س���Ϊ����
    string str;
    getline(cin,str,'\n');
    cout << "���������=" << str << endl;
}