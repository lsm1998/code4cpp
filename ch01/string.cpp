/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/13-1:02
* ���ã�
*/
#include "ch01.h"

void change_string(string *str);

/**
 * �ַ�����ʹ��
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