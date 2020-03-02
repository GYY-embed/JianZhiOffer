//面试题6：重建二叉树
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {}
};

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

//复习三种遍历，六种算法
//前序：递归
void preOrder1(TreeNode *pNode)
{
    if(pNode != nullptr) 
    {
        cout << pNode->val << " ";
        preOrder1(pNode->left);
        preOrder1(pNode->right);
    }

}
//前序：非递归
void preOrder2(TreeNode *pNode)
{
    if(pNode == nullptr) 
    {
        return;
    }
    stack<TreeNode*> NodeStack;
    cout << NodeStack.size() << endl;
    NodeStack.push(pNode);
    cout << NodeStack.size() << endl;
    //cout << NodeStack.top()->val << endl;
    while(!NodeStack.empty())
    {
        //cout << "OK" << endl;
        TreeNode *TempNode = NodeStack.top();
        cout << TempNode->val << " " << endl;
        NodeStack.pop();
        if(pNode->right!= nullptr)
        {
            NodeStack.push(TempNode->right);
        }
        if(pNode->left!= nullptr)
        {
            NodeStack.push(TempNode->left);
        }
    }
}

//中序：递归
void inOrder1(TreeNode *pNode)
{
    if(pNode != nullptr) 
    {
        preOrder1(pNode->left);
        cout << pNode->val << " ";
        preOrder1(pNode->right);
    }

}
//中序：非递归
//后序：递归
void posOrder1(TreeNode *pNode)
{
    if(pNode != nullptr) 
    {
        preOrder1(pNode->left);
        preOrder1(pNode->right);
        cout << pNode->val << " ";
    }

}

//后序：非递归

//复习宽度优先遍历

int main(int argc, char const *argv[])
{
    vector<int> pre{1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin{4, 7, 2, 1, 5, 3, 8, 6};

    TreeNode *newRoot = ConstructTree(pre, vin);
    //cout << newRoot->val;
    preOrder1(newRoot);
    cout <<endl;
    //preOrder2(newRoot);
    //cout <<endl;

    inOrder1(newRoot);
    cout <<endl;
    //inOrder2(newRoot);
    //cout <<endl;

    posOrder1(newRoot);
    cout <<endl;
    //posOrder2(newRoot);
    //cout <<endl;
    return 0;
}
