//面试题28：字符串的排列
#include <iostream>

using namespace std;


void permutation(char *pStr, char *pBegin)
{
    if(*pBegin == '\0')
    {
        cout << pStr << endl;
    }
    else
    {
        for(char *pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            cout << "OK1" << endl;
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            permutation(pStr, pBegin + 1);
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

void permutation(char *pStr)
{
    if(pStr == NULL)
        return;
    permutation(pStr, pStr);
}


int main(int argc, char const *argv[])
{
    cout << "Start:" << endl;
    char *str = "abc";
    permutation(str);
    return 0;
}
