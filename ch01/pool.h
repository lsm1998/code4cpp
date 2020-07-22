/*
* 作者：刘时明
* 时间：2020/7/23 0023-0:23
* 作用：
*/
#ifndef CODE4CPP_POOL_H
#define CODE4CPP_POOL_H

#include <string>
#include <vector>

using namespace std;

class CTask
{
protected:
    string m_strTaskName;
    void *m_ptrData;
public:
    CTask() = default;

    CTask(string &taskName) : m_strTaskName(taskName), m_ptrData(nullptr)
    {}

    virtual int Run() = 0;

    void setData(void *data);

    virtual ~CTask()
    {}
};

class CThreadPool
{
private:
    static vector<CTask*> m_vecTaskList;
    static bool shutdown;
    int m_iThreadNum;
    pthread_t *pthread_id;

    static pthread_mutex_t m_pthreadMutex;
    static pthread_cond_t m_pthreadCond;

protected:
    static void* ThreadFunc(void* threadData);

    static int MoveToIdle(pthread_t tid);

    static int MoveToBusy(pthread_t tid);

    int Create();

public:
    CThreadPool(int threadNum);

    int AddTask(CTask *task);

    int StopAll();

    int getTaskSize();
};

#endif //CODE4CPP_POOL_H
