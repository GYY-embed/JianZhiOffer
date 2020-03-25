//面试题28：字符串的排列
#include <iostream>
#include <vector>
#include <string>

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
vector<string> permutation(string s) 
{
    vector<string> res;
    permutation(s, 0, res);
    return res;
}


int main(int argc, char const *argv[])
{
    cout << "Start:" << endl;
    char *str = "abcdefgh";
    vector<string> vec = permutation(str);
    for(auto i : vec)
    {
        cout << i << endl;
        i+=1;
    }     
    return 0;
}
