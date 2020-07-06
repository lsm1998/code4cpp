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

void char_arr_string()
{
    char c[] = "hello";
    string str = "hello";
    cout << c << endl;
    cout << str.c_str() << endl;

    // �����ַ����� '\0' ��β������ʵ����󳤶Ȼ��һ
    char maxLen[5] = "hell";
    char *pointStr = (char *) "hello world";

    cout << *(pointStr + 1) << endl;
    // *(pointStr + 1) = '2';
    cout << pointStr << endl;
    pointStr = maxLen;
    cout << *pointStr << endl;
}

/**
 * �ַ����������ò���
 */
void string_base_opt()
{
    char str1[10] = "hello";
    char str2[10];
    // ��str1��ֵ���Ƹ�str1
    strcpy(str2, str1);
    cout << str2 << endl;


    float pi = 3.14F;
    // ��ֵת�ַ���
    string str = to_string(pi);
    // �ַ���ת��ֵ
    double pi_d = atof(str.c_str());
    cout << pi_d << endl;
    cout << atoi(str.c_str()) << endl;

    // �Ƚ��ַ��������Ƿ����
    if (!strcmp(str1, str2))
    {
        cout << "str1 == str2" << endl;
    } else
    {
        cout << "str1 != str2" << endl;
    }

    // �ַ�����ʽ��
    char forMate[1];
    int result = sprintf(forMate, "%s%.4f", str2, pi);
    cout << "result=" << result << endl;
    cout << forMate << endl;

    // GBK�����±����������ĵ��ַ�
    char *c = (char *) "hello,���";
    for (int i = 0; i < strlen(c); ++i)
    {
        if (c[i] > 0)
        {
            printf("%c \n", c[i]);
        } else
        {
            printf("%c%c \n", c[i], c[i + 1]);
            i++;
        }
    }
}