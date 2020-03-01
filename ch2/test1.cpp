#include <iostream>

using namespace std;

class Test
{
Test();
virtual ~Test();
};

int main(int argc, char const *argv[])
{
    //Test t1();
    cout << sizeof(Test) <<endl;
    return 0;
}

