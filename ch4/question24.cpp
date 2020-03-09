//面试题24、二叉搜索树的后序遍历序列
#include <iostream>

using namespace std;

bool VerifySequenceOfBST(int sequence[], int length)
{
    if(sequence == NULL || length <= 0)
        return false;
    int root = sequence[length - 1];

    int i = 0;
    //找到右子树的开始
    for(; i < length -1; ++i)
    {
        if(sequence[i] > root)
            break;
    }
    int j =i;
    for(; j < length - 1; ++j)
    {
        if(sequence[j] < root)
            return false;
    }

    bool left = true;
    if(i > 0)
    {
        left = VerifySequenceOfBST(sequence, i);
    }
    bool right = true;
    if(i < length - 1)
    {
        right = VerifySequenceOfBST(sequence + i, length - i - 1);
    }
    return (left && right);
}

int main(int argc, char const *argv[])
{
    int sequence[7] = {5, 7, 6, 9, 11, 10, 8};
    cout << VerifySequenceOfBST(sequence, 7) << endl;
    return 0;
}
