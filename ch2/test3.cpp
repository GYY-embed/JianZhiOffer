#include <iostream>
#include <vector>

using namespace std;

//二分查找，递归方法
int find1(int array[], int low, int high, int val)
{
    if(low > high)
        return -1;
    int mid = low + (high - low) /2;
    if(array[mid] == val)
        return mid;
    else if(array[mid] > val)
        return find1(array,low, mid - 1, val);
    else
        return find1(array, mid + 1, high, val);
}

//二分查找，非递归方式
int find2(int array[], int len, int val)
{
    if(array == nullptr || len <= 0)
        return -1;
    int low = 0;
    int high = len - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(array[mid] == val)
            return mid;
        else if (array[mid] > val)
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int array[7] = {1, 3, 5, 7, 9, 10, 13};
    cout << find1(array, 0, 6, 8) << endl;
    cout << find2(array, 7, 8) << endl;
    return 0;
}
