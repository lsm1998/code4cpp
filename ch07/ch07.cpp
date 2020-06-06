/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/29-0:14
* ���ã�
*/

#include <fstream>
#include <vector>
#include "ch07.h"

void back_read();

void ch07()
{
    back_read();
}

void back_read()
{
    fstream input("../resource/��ɪ.txt", ios::in);
    if (input.fail())
    {
        cout << "�ļ�������!!!" << endl;
        return;
    }
    char c;
    while (!input.eof())
    {
        input.get(c);
        // input.seekg(-1);
        cout << c << endl;
    }
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
 * ������
 */
void obj_stream()
{
    cout << "ObjDemo size=" << sizeof(ObjDemo) << endl;
    ObjDemo demo1(23, "lsm");
    ObjDemo demo2(23, "lw");

    fstream binaryIo("../resource/data", ios::out | ios::binary);
    binaryIo.write(reinterpret_cast<char *>(&demo1), sizeof(ObjDemo));
    binaryIo.write(reinterpret_cast<char *>(&demo2), sizeof(ObjDemo));
    binaryIo.close();

    ObjDemo newDemo1;
    binaryIo.open("../resource/data", ios::in | ios::binary);
    binaryIo.read(reinterpret_cast<char *>(&newDemo1), sizeof(ObjDemo));
    cout << newDemo1.getInfo() << endl;

    ObjDemo newDemo2;
    binaryIo.read(reinterpret_cast<char *>(&newDemo2), sizeof(ObjDemo));
    cout << newDemo2.getInfo() << endl;
}

/**
 * �����
 */
void skip_stream()
{
    fstream input("../resource/��ɪ.txt", ios::in);
    if (input.fail())
    {
        cout << "�ļ�������!!!" << endl;
        return;
    }
    char c;
    int index = 0;
    bool flag = false;
    while (!input.eof())
    {
        input >> c;
        // �ҵ� - ��λ��
        if (c == '-')
        {
            flag = true;
            break;
        }
        index++;
    }
    if (!flag)
    {
        cout << "�Ҳ������" << endl;
    }
    fstream output("../resource/��ɪ.txt", ios::out | ios::in | ios::binary);
    output.seekp(index + 4, ios::beg);
    // ȡ��ռλ��
    output << "������";
}