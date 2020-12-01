//
// Created by 刘时明 on 2020/11/28.
//

#ifndef CODE4CPP_COMMON_H
#define CODE4CPP_COMMON_H

#include <cstdio>
#include <cerrno>
#include <cstdlib>
#include <cstring>

#define MAX_LEN 4096

#define panic(...) {printf(__VA_ARGS__); printf("error no: %d error msg %s\n", errno, strerror(errno)); exit(1);}

#endif //CODE4CPP_COMMON_H
