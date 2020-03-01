//leetcode 88 合并两个有序数组

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//方法1：双指针后向扫描 时间：O(m+n) 空间O(1)
void insert1(vector<int> &v1, int length1, vector<int> &v2, int length2)
{
    int p1 = length1 -1;
    int p2 = length2 -1;
    int len = length1 + length2 -1;
    v1.resize(len+1);
    while (p1 >= 0 && p2 >=0)
    {
        v1[len--] = v1[p1] > v2[p2] ? v1[p1--] : v2[p2--];
    }
    while(p2 >= 0)
        v1[len--] = v2[p2--];
}

//方法2：copy and sort
void insert2(vector<int> &v1, int length1, vector<int> &v2, int length2)
{
    v1.resize(length1 + length2);
    copy(v2.begin(), v2.end(), v1.begin() + length1);
    sort(v1.begin(), v1.end());
}
int main()
{
    vector<int> a = {2, 3, 4, 6, 9};
    vector<int> b = {1, 5, 8, 9, 11, 17};
    insert2(a, 5, b, 6);
    for(auto i : a)
        cout << i << " ";
    cout << endl; 
    return 0;
}