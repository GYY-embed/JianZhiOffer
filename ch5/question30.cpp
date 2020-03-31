//面试题29:最小的k个数
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//方法1：快排 O(n)
int Partition(vector<int>& arr, int start, int end)
{
    if(arr.size()==0 || start < 0 || end >= arr.size())
    {
        cout<<"error!"<<endl;
        exit(0);
    }
    int v = arr[start];
    int i = start, j = end + 1;
    while(true)
    {
        while(++i <= end && arr[i] < v);
        while(--j >= start && arr[j] > v);
        if(i >= j)
            break;
        swap(arr[i], arr[j]);
    }
    arr[start] = arr[j];
    arr[j] = v;
    return j;
}
vector<int> quickSearch(vector<int>& arr, int start, int end, int k)
{
    int j = Partition(arr, start, end);
    if(j == k)
    {
        vector<int> vec;
        for(int i = 0; i <= j; i++)
        {
            vec.push_back(arr[i]);
        }
        return vec;
    }
    return j > k ? quickSearch(arr, start, j - 1, k) : quickSearch(arr, j + 1, end, k);
}
vector<int> getLeastNumbers1(vector<int>& arr, int k) 
{
    if(k == 0 || arr.size() == 0)
    {
        return vector<int>(0);
    }
    return quickSearch(arr, 0, arr.size() - 1, k - 1);
} 

//方法2：使用priority_queue
vector<int> getLeastNumbers2(vector<int>& arr, int k) 
{
    vector<int> ret;
    if(k < 1 || arr.size() < k)
        return ret;
    priority_queue<int> h;
    for(int num : arr)
    {
        if(h.size() < k)
            h.push(num);
        else
        {
            if(h.top() <= num)
                continue;
            else
            {
                h.pop();
                h.push(num);
            }
        }
    }
    while(!h.empty())
    {
        ret.push_back(h.top());
        h.pop();
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {4, 3, 2, 1, 2, 5, 3, 5, 2};
    vector<int> ret = getLeastNumbers2(vec, 5);
    for(auto i : ret)
        cout << i << " ";
    cout << endl;
    //cout << Partition(vec, 0, vec.size() - 1) << endl;
    return 0;
}


