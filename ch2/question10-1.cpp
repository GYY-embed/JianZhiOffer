//判断一个整数是不是2的整数次方
#include <iostream>

using namespace std;

#define Cal(n) {(((n)-1)&(n)) ? 0 : 1 }

int main(int argc, char const *argv[])
{
    int i = Cal(9);
    cout << i << endl;
    return 0;
}
