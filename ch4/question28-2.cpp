//28-2：八个数字放在正方体八个顶点上，相对面和相等
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
void permutation(string& s, int start, vector<string>& res)
{
    if(start == s.size()){
        res.push_back(s);
        return;
    }
    vector<bool> swapped(256, false);//记录是否交换过，防止重复
    for(int i=start; i < (int)s.size(); i++){
        if(swapped[s[i]]){//交换过就不用再次交换
            continue;
        }
        swapped[s[i]]=true;
        swap(s[start], s[i]);
        permutation(s, start + 1, res);
        swap(s[start], s[i]);
    }
}
bool permutation(string s) 
{
    vector<string> res;
    permutation(s, 0, res);
    for(auto i : res)
    {
        //cout << i << endl;
        if((i[0]+i[1]+i[2]+i[3] == i[4]+i[5]+i[6]+i[7])&&(i[0]+i[2]+i[4]+i[6] == i[1]+i[3]+i[5]+i[7])&&(i[0]+i[1]+i[4]+i[5] == i[2]+i[3]+i[6]+i[7]))
        {
            cout << i << endl;
            return true;
        }    
    }
    return false;
}

int main(int argc, const char** argv) 
{
    int num[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    //string s = "12345678";
    string s;
    for(int i = 0; i < 8 ; i++)
        s.push_back(num[i] + '0');
    cout << s <<endl;
    permutation(s);
    return 0;
}