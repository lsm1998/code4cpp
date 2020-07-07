#include "ch02.h"
#include <fcntl.h>

void linux_open(const string &filePath);

void linux_file_wr(const int &fd);

void linux_file_stat(const int &fd);

void linux_file_lock(const string &filePath);

void ch02()
{
    linux_open("/app/123.txt");

    linux_file_lock("/app/123.txt");
}

/**
 * Linux 系统API打开文件
 * @param filePath
 */
void linux_open(const string &filePath)
{
    // 打开文件（不存在则新建），返回文件描述符fd
    int fd = open(filePath.c_str(), O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
    cout << "result=" << fd << endl;
    // 文件描述符fd转为FILE指针
    FILE *file = fdopen(fd, "rw");
    cout << "mode=" << file->_mode << endl;
    // linux_file_wr(fd);
    linux_file_stat(fd);
    close(fd);
}

/**
 * Linux 系统API读写文件
 * @param fd
 */
void linux_file_wr(const int &fd)
{
    string str = "hello,刘时明";
    write(fd, str.c_str(), str.size());
    // 文件读写位置移动到文件开头
    int offset = lseek(fd, 0, SEEK_SET);
    if (offset == -1)
    {
        cout << "移动失败" << endl;
        return;
    }
    char buf[100];
    int size = read(fd, buf, 100);
    cout << "读到的字节数量=" << size << endl;
    cout << buf << endl;
}

/**
 * Linux 系统API文件状态
 * @param fd
 */
void linux_file_stat(const int &fd)
{
    struct stat st{};
    if (-1 == fstat(fd, &st))
    {
        cout << "获取stat失败" << endl;
        return;
    }
    cout << st.st_mode << endl;
    cout << st.st_blksize << endl;
    cout << st.st_gid << endl;
    cout << st.st_size << endl;
}

/**
 * 文件锁
 * @param filePath
 */
void linux_file_lock(const string &filePath)
{
    struct flock lock{};
    int res, fd = open(filePath.c_str(), O_RDWR | O_CREAT, 0777);
    if (fd > 0)
    {
        // 独占锁
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();
        res = fcntl(fd, F_SETLK, &lock);
        printf("return value of fcntl=%d \n", res);
        sleep(10);
        cout << "程序退出" << endl;
    }
}

/**
 * 文件-内存映射
 * @param filePath
 */
void linux_file_map(const string &filePath)
{

}