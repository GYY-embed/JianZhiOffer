//28-3：八皇后问题
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;


void permutation(vector<int> vec, int start, vector<vector<int> > res)
{
    if(start == vec.size() - 1)
    {
        res.push_back(vec);
        return;
    }    
    vector<bool> swapped(8, false);//记录是否交换过，防止重复
    for(int i=start; i < (int)vec.size(); i++)
    {
        if(swapped[vec[i]])
        {
            //交换过就不用再次交换
            continue;
        }
        swapped[vec[i]]=true;
        swap(vec[start], vec[i]);
        permutation(vec, start + 1, res);
        swap(vec[start], vec[i]);
    }
}

vector<vector<int> > permutation(vector<int> vec)
{
    vector<vector<int> > res;
    permutation(vec, 0, res);
    return res;
}

void EightQueen(void)
{
    vector<int> ColIndex = {0, 1, 2, 3, 4, 5, 6, 7};
    for(auto m : ColIndex)
            cout << m;
    cout << endl;
    vector<vector<int> > result;
    result = permutation(ColIndex);
    for(auto i : result)
    {
        for(auto m : i)
            cout << m;
        cout << endl;
        // for(int j = 0; j < 8; j++)
        // {
        //     for(int k = j + 1; k < 8; k++)
        //         if((j - k != i[j] - i[k]) && (k - j != i[k] - i[j]))
        //         {
        //             for(auto m : i)
        //                 cout << m;
        //             cout << endl;
        //         }    
        // }
    }
}
int main(int argc, const char** argv) 
{
    EightQueen();
    return 0;
}