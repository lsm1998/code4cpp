#include "ch02.h"
#include <fstream>

/**
 * 使用标准库
 * @param filePath
 */
void read_file_2(const string &filePath)
{
    ifstream input;
    input.open(filePath);
    string content;
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return;
    }
    // 默认按空格读取，指定getline按行读取
    while (getline(input, content))
    {
        cout << content << endl;
    }
    input.close();
}

void copy(const string &src, const string &dist)
{
    fstream input(src, ios::in | ios::binary);
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return;
    }
    fstream output(dist, ios::out | ios::binary);
    output << input.rdbuf();
    input.close();
    output.close();
}

char *read_bytes(const string &filePath)
{
    fstream input(filePath, ios::in | ios::binary);
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return nullptr;
    }
    input.seekg(0, ios::end);

    unsigned long len = input.tellg();
    auto *buffer = new char[len];
    input.seekg(0, ios::beg);
    input.read(buffer, len);
//    for (int i = 0; i < len; ++i)
//    {
//        cout << (int)buffer[i] << endl;
//    }
    return buffer;
}