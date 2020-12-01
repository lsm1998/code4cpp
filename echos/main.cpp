/**
* 作者：刘时明
* 时间：2020/12/1 0001
*/

#include "main.h"

int main()
{
    CConfig &config = CConfig::getInstance();
    config.load();
    return 0;
}