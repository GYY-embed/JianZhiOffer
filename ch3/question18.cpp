//面试题18、树的子结构
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {}
};

bool DoesTree1HaveTree2(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if(pRoot2 == NULL)
        return true;
    if(pRoot1 == NULL)
        return false;
    if(pRoot1->val != pRoot2->val)
        return false;
    return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right); 
}
bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    bool result = false;
    if(pRoot1 != NULL && pRoot2 != NULL)
    {
        if(pRoot1->val == pRoot2->val)
        {
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        }
        if(!result)
            result = HasSubtree(pRoot1->left, pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->right, pRoot2);
    }
    return result;
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
    //构建二叉树2
    vector<int> pre2{3,5,6};
    vector<int> vin2{5,3,6};

    TreeNode *newRoot2 = ConstructTree(pre2, vin2);
    preOrder1(newRoot2);
    cout <<endl;

    cout << HasSubtree(newRoot1, newRoot2) << endl;
    return 0;
}

