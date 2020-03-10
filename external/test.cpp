#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t i = 1;
        while(i)
        {
            if(i & n)
                count++;
            i = i << 1;
        }
        return count;
    }

int main(int argc, char const *argv[])
{
    cout << hammingWeight(7) << endl;
    return 0;
}
