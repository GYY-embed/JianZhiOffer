//面试题29:最小的k个数
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

//O(n)复杂度
int FindGreatestSumOfSubArray(vector<int> arr)
{
    int nCurSum = 0;
    int nGreatestSum = INT_MIN;
    for(int i = 0; i < arr.size(); i++)
    {
        if(nCurSum <= 0)
            nCurSum = arr[i];
        else
            nCurSum += arr[i];
        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }
    return nGreatestSum;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {-1, -2, -3, 10, -4, 7, 2, -5};
    cout << FindGreatestSumOfSubArray(vec) << endl;
    return 0;
}
