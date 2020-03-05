//面试题11、数值的整数次方
//注意要考虑实处小于1的情况

#include <iostream>

using namespace std;

bool InvalInput = false;
//计算正整数次幂，方法一，常规方法
double PowerWithUnsignedExp1(double base, unsigned int exp)
{
    double ret = 1.0;
    for(int i = 1; i <= exp; i++)
    {
        ret *= base;
    }
    return ret;
}

//计算正整数次幂，方法二，优化后的方法（类似于斐波那契数列的优化）
double PowerWithUnsignedExp2(double base, unsigned int exp)
{
    double ret = 1.0;
    if(exp == 0)
        return ret;
    else if(exp == 1)
        return base;
    ret = PowerWithUnsignedExp2(base, exp >> 1);
    ret *= ret;
    if(exp & 0x01 ==1)
        ret *= base;
    return ret;
}
//判断两个小数是否相同
bool equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001) && (num1 - num2 > 0.0000001))
        return true;
    else
        return false;
}
//求整数次方函数
double Power(double base, int exp)
{
    InvalInput = false;
    //参数合法性判断
    if(equal(base, 0.0) && exp <0)
    {
        InvalInput = true;
        return 0.0;
    }
    //计算指数的绝对值
    unsigned int absExp = (unsigned int)(exp);

    if(exp < 0)
    {
        absExp = (unsigned int)(-exp);
    }
    //计算正整数幂
    double ret = PowerWithUnsignedExp2(base, absExp);
    //若为负整数次方，返回1/ret
    if(exp < 0)
        ret = 1.0 / ret;

    return ret;
}


int main(int argc, char const *argv[])
{
    cout << Power(2, 2) << endl;
    cout << Power(2, 0) << endl;
    cout << Power(0, 0) << endl;
    cout << Power(2, -2) << endl;
    cout << Power(2, 4) << endl;
    cout << Power(22, 14) << endl;
    cout << Power(2, 31) << endl;
    return 0;
}

