//大数的加减乘除法
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//加法运算，模拟手算进位
void DataAdd(string str1, string str2)
{
    string s(10000, '0');
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for(int i =0; i < str1.length(); i++)
        s[i] = str1[i];
    int temp = 0;
    for(int j = 0; j < str2.length(); j++)
    {
        temp += s[j] - '0' + str2[j] - '0';
        s[j] = temp%10 + '0';
        temp /= 10;
    }
    s[str2.length()] = s[str2.length()] - '0' + temp + '0';
    reverse(s.begin(), s.end());
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    cout << str1 << " + ";
    cout << str2 << " = ";
    cout << s.substr(s.find_first_not_of('0')) << endl;
} 
//减法运算，模拟手算，先用大数减小数，最后判断是否加负号
int StrComp(string &str1, string &str2) //比较输入数字是否相同的函数，先比较长度，再进行字符串比较
{
    int len1 = str1.length();
    int len2 = str2.length();
    if(len1 > len2)
        return 0;
    else if(len1 < len2)
        return 1;
    else
    {
        if(str1 >= str2)
            return 0;
        else
            return 1;
    }
}
void DataSub(string str1, string str2)
{
    string s(10000, '0');
    bool flagEx = true;
    if(StrComp(str1, str2))
    {
        string temp;
        temp = str1;
        str1 = str2;
        str2 = temp;
        flagEx = false;
    }
    if(str1 == str2)
    {
        cout << str1 << " - " << str2 << " = " << "0";
    }
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for(int i = 0; i < str1.length(); i++)
        s[i] = str1[i];
    for(int i = 0; i < str2.length(); i++)
    {
        if(s[i] >= str2[i])
            s[i] = (s[i] - '0') -(str2[i] - '0') + '0';
        else
        {
            s[i+1] = (s[i+1] - '0') - 1 +'0';
            s[i] = (s[i] - '0') + 10 -(str2[i] - '0') + '0';
        }
    }
    if(flagEx == false)
    {
        reverse(str2.begin(), str2.end());
        cout << str2 << " - ";
        reverse(str1.begin(), str1.end());
        cout << str1 << " = ";
        reverse(s.begin(), s.end());
        cout << "-" << s.substr(s.find_first_not_of('0')) << endl;
    }
    else
    {
        reverse(str1.begin(), str1.end());
        cout << str1 << " - ";
        reverse(str2.begin(), str2.end());
        cout << str2 << " = ";
        reverse(s.begin(), s.end());
        cout << s.substr(s.find_first_not_of('0')) << endl;
    }
}
//乘法运算，模拟手算，O(n)复杂度
void DataMultiply(string str1, string str2)
{
    string s(10000, '0');
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for(int i =0; i < str1.length(); i++)
    {
        for(int j =0; j < str2.length(); j++)
        {
            int temp = (str1[i] - '0') * (str2[j] - '0');
            s[i+j+1]=s[i+j+1]-'0' + (s[i+j]-'0'+temp)/10 + '0';  
            s[i+j]=(s[i+j]-'0'+temp)%10+'0';  
        }
    }
    reverse(s.begin(), s.end());
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    if(s.find_first_not_of('0') == string::npos)
        cout << "0";
    else
        cout << str1 << " * " << str2 << " = " << s.substr(s.find_first_not_of('0')) << endl; 
}
//大数除法，当做减法来处理，用被减数不断的减去减数，记录减得次数就是商的值
//一个一个减当被减数与减数大小差距很大时效率不高，我们可以记录被减数和减数的位数之差len，将减数扩大10的len倍
//然后依次去减，一旦被减数小于减数时，将减数减小10倍，直至到原值。依次循环，去掉前置0，得出结果。
string Sub(string str1, string str2)
{
    if(StrComp(str1, str2) == 1)
        return "-1";
    //cout << str1 << " " << str2 << endl;
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    string s(10000, '0');
    for(int i =0; i < str1.length(); i++)
    {
        s[i] = str1[i];
    }
    for(int i =0; i < str2.length(); i++)
    {
        if(s[i] >= str2[i])
            s[i] = (s[i] - '0') - (str2[i] - '0') + '0';
        else
        {
            s[i+1] = s[i+1] -'0' - 1 + '0';
            s[i] = s[i] - '0' + 10 - (str2[i] - '0') +'0';
        }
    }
    reverse(s.begin(), s.end());
    if(s.find_first_not_of('0') == string::npos)
        return "0";
    else
        return s.substr(s.find_first_not_of('0'));

}
void DataDivision(string str1, string str2)
{
    string s(10000, '0');
    string ret;
    if(StrComp(str1, str2) == 1)  
    {  
        cout << str1 << " / " << str2 << " = " << "0";
    } 
    else
    {
        cout << str1 << " / " << str2 << " = ";
        int len1 = str1.length();
        int len2 = str2.length();
        int dis = len1 -  len2;
        for(int i = 0; i < dis; i++)
            str2 += '0';
        //cout << str2 << endl;
        string ans(10000, '0');
        while(dis >= 0)
        {
            int sum = 0;
            string temp;
            //cout << "str2: " << str2 << endl;
            while((temp=Sub(str1, str2))!= "-1")
            {
                sum++;
                str1 = temp;
                //cout << str1 << endl;
            }
            ans[ans.length() - dis - 1] = sum + '0';
            dis--;
            str2 = str2.substr(0, len2 + dis);
        }
        if(ans.find_first_not_of('0') == string::npos)
            cout << "0" << endl;
        else
            cout << ans.substr(ans.find_first_not_of('0')) << endl;
    }
}
int main(int argc, char const *argv[])
{
    string str1{"12345"};
    string str2{"23456"};
    string str3{"23555"};
    string str4{"5"};
    DataAdd(str1, str2); 
    DataSub(str1, str2);
    DataMultiply(str1, str2);
    DataMultiply(str3, str4);
    DataDivision(str3, str4);
    return 0;
}
