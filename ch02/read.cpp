/*
* ���ߣ���ʱ��
* ʱ�䣺2020/6/13-19:58
* ���ã�
*/
#include "ch02.h"

void readLine(const string &filePath);

void readChar(const string &filePath);

void readBuf(const string &filePath);

void repeatRead(const string &filePath);

void readSkip(const string &filePath);

void readByte(const string &filePath);

void objectStream();

/**
 * ���ļ�
 */
void read(const string &filePath)
{
    // readLine(filePath);
    // readChar(filePath);
    // readBuf(filePath);
    // repeatRead(filePath);
    //readSkip(filePath);
    readByte(filePath);
    objectStream();
}

/**
 * ���ж�ȡ
 *
 * @param filePath
 */
void readLine(const string &filePath)
{
    cout << endl << "���ж�ȡ" << endl;
    ifstream input;
    input.open(filePath);
    string content;
    if (!input.is_open())
    {
        printf("��ȡ����ָ���ļ�!!!\n");
        return;
    }
    // Ĭ�ϰ��ո��ȡ��ָ��getline���ж�ȡ
    while (getline(input, content))
    {
        cout << content << endl;
    }
    input.close();
}

/**
 * ���ַ���ȡ
 * @param filePath
 */
void readChar(const string &filePath)
{
    cout << endl << "����ַ���ȡ" << endl;
    ifstream input;
    input.open(filePath);
    if (!input.is_open())
    {
        printf("��ȡ����ָ���ļ�!!!\n");
        return;
    }
    // �������ո�ͻ���
    input >> noskipws;
    char ch;
    while (input >> ch)
    {
        printf("%c", ch);
    }
    input.close();
}

/**
 * ȫ����ȡ
 * @param filePath
 */
void readBuf(const string &filePath)
{
    cout << endl << "ȫ����ȡ" << endl;
    ifstream input;
    input.open(filePath);
    if (!input.is_open())
    {
        printf("��ȡ����ָ���ļ�!!!\n");
        return;
    }
    // ȫ����ȡ
    stringstream buffer;
    buffer << input.rdbuf();
    cout << buffer.str() << endl;
    input.close();
}

/**
 * �ظ���
 * @param filePath
 */
void repeatRead(const string &filePath)
{
    cout << endl << "��һ�ζ�" << endl;
    ifstream input;
    input.open(filePath);
    if (!input.is_open())
    {
        printf("��ȡ����ָ���ļ�!!!\n");
        return;
    }
    stringstream buffer1;
    buffer1 << input.rdbuf();
    cout << buffer1.str() << endl;
    input.clear();
    input.seekg(0);

    cout << endl << "�ڶ��ζ�" << endl;
    stringstream buffer2;
    buffer2 << input.rdbuf();
    cout << buffer2.str() << endl;
    input.close();
}

/**
 * ���������
 * @param filePath
 */
void readSkip(const string &filePath)
{
    ifstream input;
    input.open(filePath);
    if (!input.is_open())
    {
        printf("��ȡ����ָ���ļ�!!!\n");
        return;
    }
    // ����Hello���ڵ�λ�ã�����ʼλ�ú���13
    input.seekg(13, ios::beg);
    cout << "��ǰλ��=" << input.tellg() << endl;
    string content;
    // ���10���ظ��ġ�Hello��
    for (int i = 0; i < 10; ++i)
    {
        input >> content;
        cout << content << endl;
        // ����֮���ȡ��ǰλ��
        int currIndex = input.tellg();
        // ����ȥ�ظ���
        input.seekg(-(currIndex - 13), ios::beg);
    }
    input.close();
}

/**
 * ����������ȡ
 * @param filePath
 */
void readByte(const string &filePath)
{
    ifstream input;
    input.open(filePath, ios::binary);
    if (!input.is_open())
    {
        printf("��ȡ����ָ���ļ�!!!\n");
        return;
    }
    int size = 8;
    while (true)
    {
        char arr[size];
        input.read(arr, size);
        // �����ȡ���ĳ���Ϊ0����֤����ȡ�����
        if (input.gcount() == 0)
        {
            break;
        }
        cout << "��ȡһ�Σ�����=" << arr << endl;
    }
    input.close();
}

class ObjDemo
{
public:
    int age;
    string name;

    ObjDemo(int age, string name);

    string getInfo() const;
};

ObjDemo::ObjDemo(int age, string name)
{
    this->age = age;
    this->name = name;
}

string ObjDemo::getInfo() const
{
    string str;
    str.append(name).append(",").append(to_string(age));
    return str;
}

/**
 * ������
 */
void objectStream()
{
    cout << "ObjDemo size=" << sizeof(ObjDemo) << endl;
    ObjDemo demo1(23, "lsm");
    ObjDemo demo2(23, "lw");

    fstream binaryIo("../resource/data", ios::out | ios::binary);
    binaryIo.write(reinterpret_cast<char *>(&demo1), sizeof(ObjDemo));
    binaryIo.write(reinterpret_cast<char *>(&demo2), sizeof(ObjDemo));
    binaryIo.close();

    ObjDemo newDemo1(0, "");
    binaryIo.open("../resource/data", ios::in | ios::binary);
    binaryIo.read(reinterpret_cast<char *>(&newDemo1), sizeof(ObjDemo));
    cout << newDemo1.getInfo() << endl;

    ObjDemo newDemo2(0, "");
    binaryIo.read(reinterpret_cast<char *>(&newDemo2), sizeof(ObjDemo));
    cout << newDemo2.getInfo() << endl;
}