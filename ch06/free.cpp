#include <iostream>

using namespace std;

struct FreeDemo
{
public:
    FreeDemo()
    {
        cout << "FreeDemo ���캯��" << endl;
    }

    ~FreeDemo()
    {
        cout << "FreeDemo ��������" << endl;
    }

    void test()
    {
        cout << "test" << endl;
    }
};



void freeDemo()
{
    cout << "*********" << endl;
    // malloc ����ֵ����void*����
    // ���ִ���������뱨����ִ��������
    // linux man�ĵ�����malloc(0)�Ľ���
    // malloc() allocates size bytes and returns a pointer to the allocated memory.
    // The memory is not cleared. If size is 0, then malloc() returns either NULL,
    // or a unique pointer value that can later be successfully passed to free()
    FreeDemo *f1 =(FreeDemo*)malloc(0);
    if(f1 == NULL)
    {
        cout << "��ֵ" << endl;
    }
    // FreeDemo *f1 =(FreeDemo*)malloc(sizeof(FreeDemo*));
    f1->test();
    free(f1);

    FreeDemo *f2=new FreeDemo();
    f2->test();
    delete(f2);
    // ��ʱ����f1��f2���������delete��freeֻ��֪ͨ����ϵͳ���ڴ���Ա�����
    f1->test();
    f2->test();
}