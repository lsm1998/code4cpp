/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/23-0:08
* ���ã�
*/
#include "ch01.h"

void ch01()
{
    scanInput();
}

/**
 * ��ȡ��������
 */
void scanInput()
{
    /**
     * C++�У�cin��ʾ��׼����̨����
     * >> Ϊ����ȡ����
     */
    double radius = 0;
    cout << "����뾶��";
    cin >> radius;
    // scanf("%lf", &radius);
    double area = radius * radius * PI;
    cout << "Բ�����=" << area << endl;
    cout << "double���ͳ���Ϊ��" << sizeof(area) << "byte" << endl;
}

/**
 * ��ȡ�������
 */
void scanMultiple()
{
    /**
     * C++�У�double number1(0)�ȼ���double number=0
     */
    double number1(0), number2(0), number3(0);
    cout << "����������ֵ��";
    cin >> number1 >> number2 >> number3;
    cout << "ƽ��ֵ=" << (number1 + number2 + number3) / 3;
}

/**
 * ��ȡʱ���
 */
void dateDemo()
{
    /**
     * time(0)���ص�ǰʱ���
     */
    cout << "��ǰʱ���=" << time(nullptr) << endl;
}

/**
 * �������
 */
void random()
{
    /**
     * rand()����һ���������
     * srand(int)�����޸�������������ӣ�����Ĭ��Ϊ1
     */
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i)
    {
        printf("��%d��ѭ�������ֵ=%d\n", i + 1, rand());
    }
}

/**
 * if����
 */
void if_demo()
{
    int a = 10;
    while (a)
    {
        a--;
    }
    printf("%d \n", a);
}