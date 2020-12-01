/**
* 作者：刘时明
* 时间：2020/12/1 0001
*/
//
// Created by Administrator on 2020/12/1 0001.
//

#ifndef CODE4CPP_CONFIG_H
#define CODE4CPP_CONFIG_H

class CConfig
{
private:
    static CConfig *instance;

    CConfig() = default;

public:
    static CConfig& getInstance();
};

static CConfig *instance = nullptr;

#endif //CODE4CPP_CONFIG_H
