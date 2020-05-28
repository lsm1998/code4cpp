/*
* ���ߣ���ʱ��
* ʱ�䣺2020/5/24-7:02
* ���ã�
*/
#include <iostream>
#include <fstream>
#include "ch03.h"

using namespace std;

void ch03() {
    poker();
    maze("../resource/maze.txt");
    multidimensional_array();
}

void avg_demo() {
    int size = 5;
    int numbers[size];
    for (int i = 0; i < size; ++i) {
        cout << "�����" << i + 1 << "/" << size << "��Ԫ�ص�ֵ" << endl;
        cin >> numbers[i];
    }
    cout << "ƽ��ֵ=" << getAvg(numbers, size) << endl;
    cout << "���ֵ=" << getMax(numbers, size) << endl;
    cout << "sizeof=" << sizeof(numbers) << endl;

    change_arr(numbers);

    cout << numbers[0] << endl;
}

double getAvg(const int numbers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }
    return sum / (double) size;
}

int getMax(const int numbers[], int size) {
    int max = INT32_MIN;
    for (int i = 0; i < size; ++i) {
        if (max < numbers[i])max = numbers[i];
    }
    return max;
}

void change_arr(int numbers[]) {
    // �˴�sizeof����4������������int���ֽ��������������뾯��
    // warning: 'sizeof' on array function parameter 'numbers' will return size of 'int*'
    // cout << "change_arr,sizeof=" << sizeof(numbers) << endl;
    // ����������ָ�����ͣ������޸Ļ���Ч
    numbers[0] = -1;
}

/**
 * ��ʼ��һ���˿�
 */
void poker() {
    string types[] = {"����", "����", "÷��", "����"};
    string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string targets[52];

    for (int i = 0; i < sizeof(types) / sizeof(types[0]); ++i) {
        for (int j = 0; j < sizeof(ranks) / sizeof(ranks[0]); ++j) {
            targets[i * (sizeof(ranks) / sizeof(ranks[0])) + j] = types[i] + ranks[j];
        }
    }
    for (auto &target : targets) {
        cout << target << endl;
    }
}

/**
 * ���Թ�
 * @param path
 */
void maze(const string &path) {
    ifstream input;
    input.open(path);
    if (!input.is_open()) {
        printf("��ȡ����ָ���ļ�!!!\n");
        return;
    }
    int maps[10][10];
    string str;
    int index = 0;
    while (getline(input, str, '\n')) {
        for (int i = 0; i < str.length(); ++i) {
            maps[index][i] = str.at(i) - 48;
        }
        index++;
    }
    set_way(maps, 1, 1);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
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
bool set_way(int maps[10][10], int i, int j) {
    // 0����δ�߹���·��1����ǽ�壬2�����߹���·��3����ͨ·
    // ����յ��Ѿ��߹����˳�
    if (maps[9][9] == 2) {
        return true;
    } else {
        if (maps[i][j] == 0) {
            maps[i][j] = 2;
            if (set_way(maps, i + 1, j)) {
                return true;
            } else if (set_way(maps, i, j + 1)) {
                return true;
            } else if (set_way(maps, i - 1, j)) {
                return true;
            } else if (set_way(maps, i, j - 1)) {
                return true;
            } else {
                maps[i][j] = 3;
                return false;
            }
        } else {
            return false;
        }
    }
}

/**
 * ��ά����
 */
void multidimensional_array() {
    // ���鱾�ʾ���һ��ָ�룬��ά������Ƕ�άָ��
    int len1 = 10, len2 = 10, len3 = 10;
    int ***p;
    p = new int **[len3];
    for (int i = 0; i < len3; ++i) {
        p[i] = new int *[len2];
        for (int j = 0; j < len2; ++j) {
            p[i][j] = new int[len1];
            for (int k = 0; k < len1; ++k) {
                p[i][j][k] = i * len1 * len2 + j * len3 + k;
            }
        }
    }

    // ��ӡ���ݲ��ͷ�ָ���ڴ�
    for (int i = 0; i < len3; ++i) {
        for (int j = 0; j < len2; ++j) {
            for (int k = 0; k < len3; ++k) {
                cout << p[i][j][k] << ",";
            }
            delete[] p[i][j];
        }
        delete[] p[i];
    }
    delete[] p;
    cout << endl;
    // ��ʱ��Ȼ���Է��ʵ�����
    // ԭ����ֻ�Ƿ����˶���Ƭ�ڴ������Ȩ���������Ȩ���˶���Ƭ�ڴ���ʲô������˵ʲô�������������������
    cout << "�ͷź�=" << p[0] << endl;
    cout << "�ͷź�=" << p[0][0] << endl;
    cout << "�ͷź�=" << p[0][0][0] << endl;
}