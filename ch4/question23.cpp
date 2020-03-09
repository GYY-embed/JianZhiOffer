//面试题23、从上往下打印二叉树
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {}
};

void PrintFromeTopToBottom(TreeNode *pRoot)
{
    if(!pRoot)
        return;
    deque<TreeNode *> NodeDeque;
    NodeDeque.push_back(pRoot);
    while(NodeDeque.size())
    {
        TreeNode *pTemp = NodeDeque.front();
        NodeDeque.pop_front();
        cout << pTemp->val << " ";
        if(pTemp->left)
            NodeDeque.push_back(pTemp->left);
        if(pTemp->right)
            NodeDeque.push_back(pTemp->right);
    }
    cout << endl;
}

//重建二叉树
TreeNode *ConstructTree(vector<int> pre, vector<int> vin)
{
    if(pre.size() == 0 || vin.size() != pre.size())
        return nullptr;
    //使用前序遍历第一个元素作为根节点
    int root = pre[0];
    TreeNode *newNode = new TreeNode(root);

    //如果只剩一个节点了，直接返回
    if(pre.size() == 1)
        return newNode;
    
    //在中序遍历中找到根节点
    auto posi = find(vin.begin(), vin.end(), root);
    //错误检测
    if(posi == vin.end())
        return nullptr;
    
    //中序遍历中根节点左右分别为左子树和右子树
    int leftsize = posi - vin.begin();
    int rightsize = vin.end() - posi -1;

    //递归求解
    newNode->left = ConstructTree(vector<int>(pre.begin() + 1, pre.begin() + 1 + leftsize),
                    vector<int>(vin.begin(), vin.begin() + leftsize));
    newNode->right = ConstructTree(vector<int>(pre.begin() + 1 + leftsize, pre.end()),
                    vector<int>(vin.begin() + leftsize + 1, vin.end()));
    return newNode;
}

void preOrder1(TreeNode *pNode)
{
    if(pNode != nullptr) 
    {
        cout << pNode->val << " ";
        preOrder1(pNode->left);
        preOrder1(pNode->right);
    }

}
int main(int argc, char const *argv[])
{
    //构建二叉树1
    vector<int> pre1{1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin1{4, 7, 2, 1, 5, 3, 8, 6};

    TreeNode *newRoot1 = ConstructTree(pre1, vin1);
    preOrder1(newRoot1);
    cout <<endl;
    PrintFromeTopToBottom(newRoot1);
    return 0;
}