/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/23-0:08
* ���ã�
*/
#include <iostream>
#include <ctime>

using namespace std;

#define PI 3.1415926

void scanInput()
{
    /**
     * C++�У�cin��ʾ��׼����̨����
     * >> Ϊ����ȡ
     */
    double radius = 0;
    cout << "����뾶��";
    cin >> radius;
    // scanf("%lf", &radius);
    double area = radius * radius * PI;
    cout << "Բ�����=" << area << endl;

    int a = sizeof(area);
    cout << a << "byte" << endl;
}

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

void dateDemo()
{
    /**
     * time(0)���ص�ǰʱ���
     */
    cout << "��ǰʱ���=" << time(nullptr) << endl;
}

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