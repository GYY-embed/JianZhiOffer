//28-1：求字符的所有组合
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void Combination(char *s, int number, vector<char>& res)
{
    if(number == 0)
    {
        vector<char>::iterator iter = res.begin();
        for(;iter < res.end(); iter++)
            cout << *iter;
        cout << endl;
        return;
    }
    if(*s == '\0')
        return;
    res.push_back(*s);
    Combination(s + 1, number - 1, res);
    res.pop_back();
    Combination(s + 1, number, res);

}
vector<char> Combination(char *s) 
{
    vector<char> res;
    if(strlen(s) == 0)
        return res;
    for(int i = 1; i <= strlen(s); i++)
        Combination(s, i, res);
    return res;
}


int main(int argc, char const *argv[])
{
    cout << "Start:" << endl;
    char *str = "abc";
    vector<char> vec = Combination(str);
    for(auto i : vec)
    {
        cout << i << endl;
        i+=1;
    }     
    return 0;
}