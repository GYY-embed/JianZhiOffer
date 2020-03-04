//面试题8：旋转数组中的最小数
#include <iostream>
#include <exception>

using namespace std;


int MinInOrder(int num[], int index1, int index2)
{
    int ret = num[index1];
    for(int i = 0; i <= index2; i++)
    {
        if(ret > num[i])
            ret = num[i];
    }
    return ret;
}
int min(int num[], int length)
{
    if(num == nullptr || length <= 0)
        return -1;
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while (num[index1] >= num[index2])
    {
        if(index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2)/2;
        if(num[index1] == num[index2] && num[indexMid] == num[index1])
            return MinInOrder(num, index1, index2);
        if(num[indexMid] >= num[index1])
            index1 = indexMid;
        else if (num[indexMid] <= num[index2])
            index2 = indexMid;
    }
    return num[indexMid];
     
    
}
int main(int argc, char const *argv[])
{
    int array1[5] = {3, 4, 5, 1, 2};
    int array2[5] = {1, 1, 1, 0, 1};
    cout << min(array2, 5) << endl;
    return 0;
}
