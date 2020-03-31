//面试题29:数组中出现次数超过一半的数字
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//方法1：使用哈希表
int majorityElement1(vector<int>& nums)
{
    if(nums.size() == 0)
        return -1;
    unordered_map<int, int> mp;
    for(auto it : nums)
    {
        mp[it]++;
        if(mp[it]>nums.size()/2)
            return it;
    }
    return 0;
}
//方法2：
int majorityElement2(vector<int>& nums)
{
    int result = nums[0];
    int times = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        if(times == 0)
        {
            result = nums[i];
            times = 1;
        }
        else if(nums[i] == result)
            times++;
        else
            times--;
    }
    if(times > 0)
        return result;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 3, 2, 4, 2, 2, 2, 5, 2};
    cout << majorityElement1(vec) << endl;
    cout << majorityElement2(vec) << endl;
    return 0;
}
