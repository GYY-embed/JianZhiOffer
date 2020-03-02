//面试题5：反向打印链表
#include <iostream>
#include <stack>

using namespace std;
struct ListNode
{
    int m_nkey;
    ListNode* m_pNext;
};

//方法1：使用栈，先做一次正向遍历，依次入栈，然后从栈中弹出所有元素，依次打印
void print1(ListNode *pHead)
{
    stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {    
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode->m_nkey << " ";
        nodes.pop();
    }
    cout << endl;
}

//方法二：使用递归
void print2(ListNode *pHead)
{
    ListNode* pNode = pHead;
    if(pNode != nullptr)
    {
        if(pNode->m_pNext != nullptr)
            print2(pNode->m_pNext);
        cout << pNode->m_nkey << " ";
    }
}


void insert(ListNode *pHead, int val)
{
    ListNode *pNode = new ListNode();
    ListNode* TheHead = pHead;
    pNode->m_nkey = val;
    pNode->m_pNext = nullptr;
    while(TheHead->m_pNext != NULL)
        TheHead = TheHead->m_pNext;
    TheHead->m_pNext = pNode;
}
int main(int argc, char const *argv[])
{
    ListNode *pHead = new ListNode();
    pHead->m_nkey = 7;
    insert(pHead, 1);
    insert(pHead, 3);
    insert(pHead, 5);
    insert(pHead, 7);
    insert(pHead, 9);
    insert(pHead, 11);
    print1(pHead);
    print2(pHead);
    cout << endl;
    return 0;
}

