#ifndef CODE4CPP_CH02_H
#define CODE4CPP_CH02_H

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

void read_file_1(const string &filePath);

void open_dir(const string &path);

#endif //CODE4CPP_CH02_H
