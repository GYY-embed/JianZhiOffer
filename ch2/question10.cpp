//面试题10、二进制中1的个数
#include <iostream>

using namespace std;

//方法1：不全面，不支持负数
int CountOne1(int num)
{
    int count = 0;
    while (num)
    {
        if(num & 1)
            count++;
        num = num >> 1;
    }
    return count;
}
//方法2：支持负数
int CountOne2(int num)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(num & flag)
            count++;
        flag = flag << 1;
    }
    return count;
}
//方法3：位运算巧妙的方法
int CountOne3(int num)
{
    int count = 0;
    while(num)
    {
        ++ count;
        num = (num - 1) & num;
    }
    return count;
}
int main(int argc, char const *argv[])
{
    cout << CountOne3(-9) << endl;
    return 0;
}
