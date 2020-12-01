/**
* 作者：刘时明
* 时间：2020/12/1 0001
*/

#include <config.h>

CConfig &CConfig::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CConfig();
    }
    return *instance;
}
