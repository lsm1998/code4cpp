/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/29-0:14
* ���ã�
*/

#include <fstream>
#include <vector>
#include "ch07.h"

void ch07()
{
    string src = R"(C:\Users\Administrator\Desktop\Dust)";
    string dist = R"(C:\Users\Administrator\Desktop\Dust2)";
    copy(dist,src);
}

/**
 * �ı���
 * @param filePath
 */
void write_file(const string *filePath)
{
    // ��д�롢׷�ӵķ�ʽ���ļ����ļ������ڻᴴ��
    ofstream output(*filePath, ios::out | ios::app);

    output << "hello" << endl;

    output << "go to here!" << endl;

    output.close();
}

/**
 * �ı���
 * @param filePath
 */
vector<string> *read_file(const string *filePath)
{
    auto *v = new vector<string>();
    ifstream input(*filePath);
    if (input.fail())
    {
        cout << "�ļ�������!!!" << endl;
        return v;
    }
    string str;
    while (getline(input, str, '\n'))
    {
        v->push_back(str);
    }
    input.close();
    return v;
}