/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/29-0:14
* ���ã�
*/

#include <fstream>
#include <vector>
#include <dirent.h>
#include <cstring>
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
    string dist = R"(C:\Users\Administrator\Desktop\starts\sst\bat\www\fuck\com)";
    string src = R"(C:\Users\Administrator\Desktop\timg_1.png)";
    // copy_file(&dist, &src);
    // make_dirs(&dist);
    // copy(&dist, &src);
    v->clear();
    getFiles(R"(C:\Users\Administrator\Desktop)", v);
    for (auto &i : *v)
    {
        cout << i << endl;
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
 * ʹ�ö�����������ļ�����
 * @param dist
 * @param src
 */
void copy_file(const string *dist, const string *src)
{
    fstream input(*src, ios::in | ios::binary);
    fstream output(*dist, ios::out | ios::binary);
    int size = 1024;
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

void copy(const string *dist, const string *src)
{
    cout << mkdir(dist->c_str()) << endl;
    // �ж��Ƿ�ΪĿ¼
//    DIR *dir = opendir(reinterpret_cast<const char *>(src));
//    if (dir == NULL)
//    {
//        // ����Ŀ¼
//        copy_file(dist, src);
//    } else
//    {
//        //����Ŀ¼
//        mkdir(dist->c_str());
//        struct dirent *dp;
//        while ((dp = readdir(dir)) != NULL)
//        {
//            if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
//            {
//                continue;
//            }
//        }
//    }
//    fstream input(*src, ios::in | ios::binary);
}

/**
 * ֧�ֶ༶Ŀ¼����
 * @param dirs
 */
void make_dirs(const string *dirs)
{
    int index;
    string temp = *dirs;

    cout << temp << endl;
    string appendStr;
    while ((index = temp.find('\\')) != -1)
    {
        string sub = temp.substr(0, index);
        if (appendStr.length() != 0)
        {
            appendStr.append("\\");
        }
        appendStr.append(sub);
        if (_access(appendStr.c_str(), 0) == -1)
        {
            mkdir(appendStr.c_str());
        }
        temp = temp.substr(index + 1, temp.length());
    }
    // ׷�����һ��
    appendStr.append("\\").append(temp.substr(index + 1, temp.length()));
    if (_access(appendStr.c_str(), 0) == -1)
    {
        mkdir(appendStr.c_str());
    }
}

void getFiles(string path, vector<string> *files)
{
    //�ļ����
    long hFile = 0;
    //�ļ���Ϣ
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            //�����Ŀ¼,����֮
            //�������,�����б�
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            } else
            {
                files->push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
            cout << _findnext(hFile, &fileinfo) << endl;
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}