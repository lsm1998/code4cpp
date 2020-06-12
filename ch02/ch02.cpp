/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/23-23:47
* ���ã�
*/
#include <cmath>
#include <cstdio>
#include <iostream>
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