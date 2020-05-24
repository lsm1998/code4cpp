/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/23-23:47
* ���ã�
*/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include "ch02.h"

using namespace std;

void ch02()
{
    read_file("../resource/hello.java");

    write_file("../resource/hello.txt", "hello");
}

/**
 * ������ѧ����
 */
void math_demo()
{
    double PI = M_PI;
    printf("%lf\n", sqrt(PI));

    printf("%lf\n", sin(PI));
    printf("%lf\n", cos(PI));

    cout << "����ȡ��=" << ceil(PI) << endl;
    cout << "����ȡ��=" << floor(PI) << endl;

    double ma = max(PI, M_E);
    double mi = min(PI, M_E);
    cout << "���ֵ=" << ma << endl;
    cout << "��Сֵ=" << mi << endl;
}

/**
 * �ַ�
 */
void char_demo()
{
    int a = 'a';
    int z = 'z';
    int A = 'A';
    int Z = 'Z';
    cout << a << endl;
    cout << z << endl;
    cout << A << endl;
    cout << Z << endl;
    // ���������ӵĻ�ÿ�������ظ���ֵ
    srand(time(nullptr));
    // ��������ַ�
    for (int i = 0; i < 10; ++i)
    {
        int temp = rand();
        if (temp % 2)
        {
            cout.put((char) (temp % 26 + a));
        } else
        {
            cout.put((char) (temp % 26 + A));
        }
    }
    cout << endl;
}

/**
 * �ַ���
 */
void string_demo()
{
    cout << "����������֣�" << endl;
    // ʹ��char����ﵽSting��Ч��
    char *charArr[10];
    scanf("%s", &charArr);
    printf("��ã�%s\n", charArr);

    string name;
    // ��ȡ�ַ�������
    // scanf("%s",name.c_str());
    // cin >> name; �Կհ׷�Ϊ����
    // getline(cin,name,'\n'); �Ի���Ϊ����

    string str = "hello world!";

    str.append(" by lsm");
    // str.clear();
    change_string(&*&*(&str));

    cout << str << endl;
    cout << "str����=" << str.length() << endl;
    cout << "str����=" << str.capacity() << endl;

    printf("%s\n", str.c_str());

    cout << &str << endl;
}

/**
 * ָ�봫�ݴﵽ�޸ĵ�Ŀ�ģ�����string&����Ҳ���Դﵽ��ͬ����
 * @param str
 */
void change_string(string *str)
{
    (*str).append(" end");
}


/**
 * ���ļ�
 */
void read_file(const string &filePath)
{
    ifstream input;
    input.open(filePath);
    string content;
    if (!input.is_open())
    {
        printf("��ȡ����ָ���ļ�!!!\n");
        return;
    }
    // ȫ����ȡ
    stringstream buffer;
    buffer << input.rdbuf();
    cout << buffer.str();

    // ���ж�ȡ
    while (getline(input, content))
    {
        cout << content << endl;
    }

    // ���ո��ȡ
    while (input >> content)
    {
        // input.eof() ����false��Ϊ��ȡ���
        cout << content << endl;
    }
    input.close();
}

void write_file(const string &filePath, const string &content)
{
    ofstream output;
    // ��д�롢׷�ӵķ�ʽ���ļ����ļ������ڻᴴ��
    output.open(filePath, ios::out | ios::app);
    output << content;
    output.close();
}