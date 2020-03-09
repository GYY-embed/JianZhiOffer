//面试题24拓展、二叉搜索树的前序遍历序列
#include <iostream>

using namespace std;

bool VerifySequenceOfBST(int sequence[], int length)
{
    if(sequence == NULL || length <= 0)
        return false;
    int root = sequence[0];

    int i = 1;
    //找到右子树的开始
    for(; i < length; ++i)
    {
        if(sequence[i] > root)
            break;
    }
    int j = i;
    for(; j < length; ++j)
    {
        if(sequence[j] < root)
            return false;
    }

    bool left = true;
    if(i > 1)
    {
        left = VerifySequenceOfBST(sequence + 1, i - 1);
    }
    bool right = true;
    if(i < length)
    {
        right = VerifySequenceOfBST(sequence + i, length - i);
    }
    return (left && right);
}

int main(int argc, char const *argv[])
{
    //int sequence[7] = {5, 7, 6, 9, 11, 10, 8};
    //int sequence[7] = {8, 6, 5, 7, 10, 9, 11};
    int sequence[6] = {8, 6, 7, 10, 9, 11};
    cout << VerifySequenceOfBST(sequence, 6) << endl;
    return 0;
}
