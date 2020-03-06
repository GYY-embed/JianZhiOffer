//面试题14、调整数组顺序使奇数位于偶数前面
#include <iostream>

using namespace std;

//方法1：使用双指针
void ReOrder1(int array[], int length)
{
    int *p1 = array,*p2 = array + length -1;
    while(p1 < p2)
    {
        while(p1 < p2 && (*p1 & 0x01) != 0)
            p1++;
        while(p1 < p2 && (*p2 & 0x01) == 0)
            p2--;
        if(p1 < p2)
        {
            int temp = *p1;
            *p1 = *p2;
            *p2 = temp;
        }
    }
}

//方法2：可扩展性的解法
void ReOrder2(int array[], int length, bool (*func)(int))
{
    int *p1 = array,*p2 = array + length -1;
    while(p1 < p2)
    {
        while(p1 < p2 && func(*p1) != 0)
            p1++;
        while(p1 < p2 && func(*p2) == 0)
            p2--;
        if(p1 < p2)
        {
            int temp = *p1;
            *p1 = *p2;
            *p2 = temp;
        }
    }
}
bool isEven(int n)
{
    return (n & 1) !=0;
}
int main(int argc, char const *argv[])
{
    int data[20]={57,13,95,13,77 ,41,83,62,25,78 ,53,19,92,33,75 ,46,85,61,22,48};
    int data1[1] = {2};
    for(int i = 0; i < sizeof(data)/sizeof(int); i++)
        cout << data[i] << " ";
    cout << endl;
    //ReOrder1(data, 20);
    ReOrder2(data, 20, isEven);
    for(int i = 0; i < sizeof(data)/sizeof(int); i++)
        cout << data[i] << " ";
    cout << endl;
    return 0;
}
