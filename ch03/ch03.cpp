/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/24-7:02
* ���ã�
*/
#include <iostream>
#include <fstream>
#include "ch03.h"

using namespace std;

void ch03()
{
    poker();
    maze("../resource/maze.txt");
}

void avg_demo()
{
    int size = 5;
    int numbers[size];
    for (int i = 0; i < size; ++i)
    {
        cout << "�����" << i + 1 << "/" << size << "��Ԫ�ص�ֵ" << endl;
        cin >> numbers[i];
    }
    cout << "ƽ��ֵ=" << getAvg(numbers, size) << endl;
    cout << "���ֵ=" << getMax(numbers, size) << endl;
    cout << "sizeof=" << sizeof(numbers) << endl;

    change_arr(numbers);

    cout << numbers[0] << endl;
}

double getAvg(const int numbers[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += numbers[i];
    }
    return sum / (double) size;
}

int getMax(const int numbers[], int size)
{
    int max = INT32_MIN;
    for (int i = 0; i < size; ++i)
    {
        if (max < numbers[i])max = numbers[i];
    }
    return max;
}

void change_arr(int numbers[])
{
    // �˴�sizeof����4������������int���ֽ��������������뾯��
    // warning: 'sizeof' on array function parameter 'numbers' will return size of 'int*'
    // cout << "change_arr,sizeof=" << sizeof(numbers) << endl;
    // ����������ָ�����ͣ������޸Ļ���Ч
    numbers[0] = -1;
}

/**
 * ��ʼ��һ���˿�
 */
void poker()
{
    string types[] = {"����", "����", "÷��", "����"};
    string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string targets[52];

    for (int i = 0; i < sizeof(types) / sizeof(types[0]); ++i)
    {
        for (int j = 0; j < sizeof(ranks) / sizeof(ranks[0]); ++j)
        {
            targets[i * (sizeof(ranks) / sizeof(ranks[0])) + j] = types[i] + ranks[j];
        }
    }
    for (auto &target : targets)
    {
        cout << target << endl;
    }
}

/**
 * ���Թ�
 * @param path
 */
void maze(const string &path)
{
    ifstream input;
    input.open(path);
    if (!input.is_open())
    {
        printf("��ȡ����ָ���ļ�!!!\n");
        return;
    }
    int maps[10][10];
    string str;
    int index = 0;
    while (getline(input, str, '\n'))
    {
        for (int i = 0; i < str.length(); ++i)
        {
            maps[index][i] = str.at(i) - 48;
        }
        index++;
    }
    set_way(maps, 1, 1);

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << maps[i][j];
        }
        cout << endl;
    }
}

/**
 * ���Թ���ʵ�ַ���
 * @param maps
 * @param i
 * @param j
 * @return
 */
bool set_way(int maps[10][10], int i, int j)
{
    // 0����δ�߹���·��1����ǽ�壬2�����߹���·��3����ͨ·
    // ����յ��Ѿ��߹����˳�
    if (maps[9][9] == 2)
    {
        return true;
    } else
    {
        if (maps[i][j] == 0)
        {
            maps[i][j] = 2;
            if (set_way(maps, i + 1, j))
            {
                return true;
            } else if (set_way(maps, i, j + 1))
            {
                return true;
            } else if (set_way(maps, i - 1, j))
            {
                return true;
            } else if (set_way(maps, i, j - 1))
            {
                return true;
            } else
            {
                maps[i][j] = 3;
                return false;
            }
        } else
        {
            return false;
        }
    }
}