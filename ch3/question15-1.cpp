//拓展：寻找链表的中间节点
//快慢指针
#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

ListNode *FindMidNode(ListNode *pListHead)
{
    if(pListHead == NULL)
        return NULL;
    ListNode *FastNode = pListHead;
    ListNode *LowNode = pListHead;
    while(FastNode->m_pNext != NULL)
    {
        if(FastNode->m_pNext != NULL)
            FastNode = FastNode->m_pNext;
        if(FastNode->m_pNext != NULL)
            FastNode = FastNode->m_pNext;
        LowNode = LowNode->m_pNext;
    }
    return LowNode;
}

ListNode *AddNode(ListNode *pListHead, int num)
{
    ListNode *Node = new (ListNode);
    Node->m_nValue = num;
    Node->m_pNext = pListHead;
    return Node;
}
int main(int argc, char const *argv[])
{
    ListNode *pHead = new (ListNode);
    pHead->m_nValue = 3;
    pHead->m_pNext = NULL;
    pHead = AddNode(pHead, 4);
    pHead = AddNode(pHead, 5);
    pHead = AddNode(pHead, 8);
    pHead = AddNode(pHead, 9);
    pHead = AddNode(pHead, 7);
    if(FindMidNode(pHead)!=NULL)
        cout << FindMidNode(pHead)->m_nValue << endl;
    else
        cout << "Error!" << endl;
    return 0;
}
