/*
* 作者：刘时明
* 时间：2020/7/24 0024-0:33
* 作用：
*/
#include <arpa/inet.h>
#include "ch03.h"

void ip_demo()
{
    struct in_addr ia{};
    inet_aton("127.0.0.1", &ia);
    cout << "ia.s_addr=" << ia.s_addr << endl;
    // 转为点分十进制
    cout << "real_ip=" << inet_ntoa(ia) << endl;
}