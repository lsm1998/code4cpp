#include <iostream>
#include "main.h"

using namespace std;

int main(int argc, char *argv[])
{
    printf("Content-Type: text/html\n\n");
    cout << "Hello, World!" << endl;
    cout << "你" << "配" << "吗？" << endl;
    cout << 0xFF << endl;
    for (int i = 0; i < argc; ++i)
    {
        cout << "参数 :" << i << " =" << argv[i] << endl;
    }
    ch03();
    return 0;
}