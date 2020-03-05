//面试题12、打印1到最大的n位数
#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

//实现数组内的整数加法
bool Increment(char *number)
{
    bool isOverflow = false;//是否到达最大的标志
    int nTakeOver = 0;//进位标志
    int nLength = strlen(number);

    for(int i = nLength - 1; i >= 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if(i == nLength -1)
            nSum ++;
        if(nSum >= 10)
        {
            if(i == 0)
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}
//打印数字
void PrintNumber(char *number)
{
    bool isBegining0 = true;
    int nLength = strlen(number);

    for(int i = 0; i < nLength; ++i)
    {
        if(isBegining0 && number[i] != '0')
            isBegining0 = false;
        if(!isBegining0)
            cout << number[i];
    }
    cout << "\t";
}
//方法1：使用模拟整数加法的方式
void Print1ToMaxOfDigits1(int n)
{
    if(n <= 0)
        return;
    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    //cout << number << endl;
    while(!Increment(number))
    {
        //cout << number << endl;
        PrintNumber(number);
    }
    cout << endl;
    delete []number;
}

//方法2：数字排列解法
void Print1ToMaxOfDigits2Recursively(char *number, int length, int index)
{
    if(index == length -1)
    {
        PrintNumber(number);
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfDigits2Recursively(number, length, index + 1);
    }
}
void Print1ToMaxOfDigits2(int n)
{
    if(n <= 0)
        return;
    char *number = new char[n+1];
    number[n] = '\0';
    for(int i = 0; i < 10; ++i)
    {
        //cout << " OK " << endl;
        number[0] = i + '0';
        //cout << number << endl;
        Print1ToMaxOfDigits2Recursively(number, n, 0);
    }
}

int main(int argc, char const *argv[])
{
    //cout << PrintToMaxOfDigits(10) << endl;
    Print1ToMaxOfDigits2(1);
    cout << endl;
    return 0;
}
