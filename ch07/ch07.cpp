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
    string path = "hello.txt";
    // write_file(&path);
    vector<string> *v = read_file(&path);

    for (auto &i : *v)
    {
        cout << i << endl;
    }
    string dist = R"(C:\Users\Administrator\Desktop\timg_2.png)";
    string src = R"(C:\Users\Administrator\Desktop\timg_1.png)";
    copy_file(&dist, &src);
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

/**
 * ʹ�ö�����������ļ�����
 * @param dist
 * @param src
 */
void copy_file(const string *dist, const string *src)
{
    fstream input(*src, ios::in | ios::binary);
    fstream output(*dist, ios::out | ios::binary);
    int size = 10;
    while (true)
    {
        char arr[size];
        input.read(arr, size);
        cout << "д��һ��," << size << endl;
        int len = input.gcount();
        if (len == 0)
        {
            break;
        }
        output.write(arr, len);
    }
    input.close();
}