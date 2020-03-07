#include <iostream>
#include <vector>

using namespace std;

int cuttingRope(int number) {
    if(number < 2) return 0;
    if (number == 2) return 1;
    if (number == 3) return 2;
    
    int *f = new int[number + 1];
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    
    // f(n) n大于3时，表示切若干刀后的最大值
    for (int i = 4; i <= number; i ++) {
        int rmax = i;
        for (int j = 1; j <= i / 2; j ++) {
            rmax = max(rmax, f[j] * f[i - j]);
        }
        f[i] = rmax;
    }
    
    int res = f[number];
    delete[] f;
    
    return res;
}

int main(int argc, char const *argv[])
{
    cout << cuttingRope(6) << endl;
    return 0;
}
