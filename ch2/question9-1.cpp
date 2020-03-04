//斐波那契数列的拓展题：青蛙跳台阶
#include <iostream>

using namespace std;

long long frag_jump(unsigned int floor)
{
    int data[2] = {1, 2};
    long long MinusOne = data[1];
    long long MinusTwo = data[0];
    long long WayNums = 0;
    if(floor == 0)
        return 0;
    else if (floor == 1)
        WayNums = data[0];
    else if (floor == 2)
        WayNums = data[1];
    else
    {
        for(unsigned int i = 3; i <= floor; i++)
        {
            WayNums = MinusOne + MinusTwo;
            MinusTwo = MinusOne;
            MinusOne = WayNums;
        }
    }
    return WayNums;
}
int main(int argc, char const *argv[])
{
    cout << frag_jump(2) << endl;
    cout << frag_jump(3) << endl;
    cout << frag_jump(4) << endl;
    cout << frag_jump(5) << endl;
    cout << frag_jump(100) << endl;

    return 0;
}

