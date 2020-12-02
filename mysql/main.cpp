#include <iostream>
#include <memory>
#include <mysql/jdbc.h>

using namespace std;
using namespace sql;

int main()
{
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *conn = nullptr;
    try
    {
        driver = sql::mysql::get_mysql_driver_instance();
        conn = driver->connect("tcp://localhost:3306/booktik", "root", "123456");
        cout << "连接成功" << endl;
    }
    catch (...)
    {
        cout << "连接失败" << endl;
    }
    sql::Statement* stat = conn->createStatement();
    stat->execute("set names 'utf8'");
    ResultSet *res;
    res = stat->executeQuery("SELECT * FROM BOOK");
    while (res->next())
    {
        cout << "    ID:" << res->getString("id") << endl;
        cout << "BOOKNAME:" << res->getString("bookname") << endl;
        cout << "    SIZE:" << res->getString("size") << endl;

    }
    if (conn != 0)
    {
        delete conn;
    }
    return 0;
}