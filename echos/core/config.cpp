/**
* 作者：刘时明
* 时间：2020/12/1 0001
*/

#include <config.h>

CConfig *CConfig::instance = nullptr;

CConfig &CConfig::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CConfig();
    }
    return *instance;
}

bool CConfig::load()
{
    this->list = new std::list<std::string>();
    list->push_back("hello");
    list->push_back("world");
    list->push_back("!!!");
    return false;
}

std::string CConfig::getItem(std::string key)
{
    return "";
}

//int CConfig::foreach()
//{
//    auto start = this->list->begin();
//
//    while (start != this->list->end())
//    {
//        printf("%s \n", start);
//        start++;
//    }
//    return 0;
//}
