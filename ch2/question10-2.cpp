//计算一个数转变为另一个数需要改变几位
#include <iostream>

using namespace std;

unsigned int Change(int num1, int num2)
{
    int temp = num1 ^ num2;
    cout << temp << endl;
    unsigned int i = 1;
    int count = 0;
    while(i)
    {
        if(i & temp)
            count++;
        i = i << 1;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    cout << Change(10, 13) << endl;
    return 0;
}
