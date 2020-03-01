#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

//使用string容器，和string流
string del_space(string &str)
{
    string temp, ret;
    string space = "%20";
    istringstream in(str);
    if(str.size() != 0)
    {   
        while(in >> temp)
        {
            ret += temp;
            ret += space;
        }
        ret.erase(ret.end()-3,ret.end());    
        return ret;
    }
    else
        return str;
}

//在原字符串数组上进行替换
char *del_space2(char str[], int length)
{
    if(str == NULL && length <= 0)
        return 0;
    int size = strlen(str), newsize;
    int SpaceNum = 0;
    for(int i = 0; i < size; i++)
    {
        if(str[i] == ' ')
        {
                ++SpaceNum;
        }
    }
    cout << size << "  " << SpaceNum << endl;
    newsize = size + SpaceNum * 2;

    char *p1 = str + size;
    char *p2 = str + newsize;
    while(p1 >= str)
    {
        if(*p1 != ' ')    
            *p2-- = *p1;
        else
        {
            *p2-- = '0';
            *p2-- = '2';
            *p2-- = '%';
        }
        --p1;
    }
    return str;
}


int main(int argc, char const *argv[])
{
    string str = "We are happy.";
    //char  cstr[50]= "We are happy.";
    char  cstr[50]= " ";//只有一个等号
    char  cstr[50]= "";//空字符串
    char  cstr[50]= "We";//无空格
    string str1 = "We";
    cout << str << endl;
    cout << del_space(str1) << endl;
    cout << del_space2(cstr,50) << endl;
    return 0;
}

