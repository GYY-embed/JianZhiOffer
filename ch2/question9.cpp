//面试题9：斐波那契数列
#include <iostream>

using namespace std;

//方法1：常规笨办法，直观但是效率不高
long long Fibonacci1(unsigned int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    else
        return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}
//方法2：较好的方法，保存前两个数
long long Fibonacci2(unsigned int n)
{
    int result[2] = {0, 1};
    if(n < 2)
        return result[n];
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for(unsigned int i = 2; i <= n; i++)
    {
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    return fibN;
}
int main(int argc, char const *argv[])
{
    cout << Fibonacci2(10) << endl;
    cout << Fibonacci2(100) << endl;
    /* code */
    return 0;
}
