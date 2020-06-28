#include "ch11.h"

template<class T>
T sum(T a[], int n);

template<class T>
T product(T a[], int n);

template<class T>
T custom(T a[], int n);

void accumulateDemo()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n1 = sum(arr, sizeof(arr) / sizeof(int));
    int n2 = product(arr, sizeof(arr) / sizeof(int));
    int n3 = custom(arr, sizeof(arr) / sizeof(int));
    cout << "result=" << n1 << endl;
    cout << "result=" << n2 << endl;
    cout << "result=" << n3 << endl;
}

/**
 * �����ۼӺ�
 * @tparam T
 * @param a
 * @param n
 * @return
 */
template<class T>
T sum(T a[], int n)
{
    T theSum = 0;
    return accumulate(a, a + n, theSum);
}

/**
 * ����˻�
 * @tparam T
 * @param a
 * @param n
 * @return
 */
template<class T>
T product(T a[], int n)
{
    T theProduct = 1;
    return accumulate(a, a + n, theProduct, multiplies<T>());
}

/**
 * �Զ�������ͣ���������
 * 1.�����ż������ǰԪ��*2��
 * 2.�������ż������ǰԪ��+1��
 * @tparam E
 */
template<typename E>
struct customFunc : public binary_function<E, E, E>
{
    // _GLIBCXX14_CONSTEXPR
    E
    // prev ������һ�ε�Ԫ�أ���һ��Ϊָ���ĳ�ʼֵ
    // item ����ǰԪ��
    operator()(const E &prev, const E &item) const
    {
        // �ȼ��� item%2 != 0
        if (item % 2)
        {
            return prev + (item + 1);
        } else
        {
            return prev + item * 2;
        }
    }
};

template<class T>
T custom(T a[], int n)
{
    T theCustom = 0;
    return accumulate(a, a + n, theCustom, customFunc<T>());
}