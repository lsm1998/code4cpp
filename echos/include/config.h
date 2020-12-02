/**
* 作者：刘时明
* 时间：2020/12/1 0001
*/

#ifndef CODE4CPP_CONFIG_H
#define CODE4CPP_CONFIG_H

#include <list>
#include <string>

class CConfig
{
private:
    static CConfig *instance;

    CConfig() = default;

    CConfig(CConfig &) = default;

    std::list<std::string> *list;

public:

    static CConfig &getInstance();

    /**
     * 加载配置文件
     * @return
     */
    bool load();

    /**
     * 获取一项配置
     * @param key
     * @return
     */
    std::string getItem(std::string key);
};

#endif //CODE4CPP_CONFIG_H
