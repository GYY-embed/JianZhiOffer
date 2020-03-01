#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char str1[] = "hello world";
    char str2[] = "hello world";
    char *str3 = "hello world";
    char *str4 = "hello world";

    if(str1 == str2)
        cout << "1,2 : equal!" << endl;
    else
        cout << "1,2 : not equal!" << endl;

    if(str3 == str4)
        cout << "3,4 : equal!" << endl;
    else
        cout << "3,4 : not equal!" << endl;
    /* code */
    return 0;
}
