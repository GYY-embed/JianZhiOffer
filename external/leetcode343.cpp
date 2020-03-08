//LeetCode343：剪绳子
/*
    给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
    每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？
    例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

    答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof
*/
#include <iostream>
#include <vector>

using namespace std;

//方法1：记录前值，大化小
int cuttingRope1(int number)
{
    if(number < 3) return number - 1;
    int *vec = new int[number + 1];
    vec[1] =  1;
    vec[2] =  2;
    vec[3] =  3;

    for(int i = 4; i <= number; i++)
    {
        int rmax = i;
        for(int j = 1; j <= i/2; j++)
            rmax = max(rmax, vec[j]*vec[i-j]);
        vec[i] = rmax;
    } 
    int res = vec[number];
    delete[] vec;
    return res;
}

//方法2：巧妙方法
/*
    分析：
        x>=5时 3*(5-3) > x
        x = 4 时 x = 2 * 2
        x = 2 时 2 * 2 * 2 < 3 * 3 所以最多两个2
*/
int cuttingRope2(int number)
{
    if(number <= 3) return number - 1;
        long res = 1;
        //一个2
        if(number % 3 == 2)
        {
            number -= 2;
            res *= 2;
        }

        if(number % 3 == 1)
        {
            number -= 4;
            res *= 4;
        }

        while(number/3)
        {
            res *= 3;
            number -= 3;
            res %=  1000000007;
        }
        return res;
}

int main(int argc, char const *argv[])
{
    cout << cuttingRope1(10) << endl;
    cout << cuttingRope2(500) << endl;
    return 0;
}
