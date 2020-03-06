//面试题15：链表中倒数第K个节点
#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
{
    ListNode *pAHead = pListHead;
    ListNode *pBehind = NULL;
    if(pListHead == NULL || k == 0)
        return NULL;
    for(unsigned int i = 0; i < k -1; i++)
    {
        if(pAHead->m_pNext != NULL)
            pAHead = pAHead->m_pNext;
        else
            return NULL;
    }
    pBehind = pListHead;
    while(pAHead->m_pNext != NULL)
    {
        pAHead = pAHead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
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
    int value;
    if(FindKthToTail(pHead, 3) != NULL)
        cout << FindKthToTail(pHead, 3)->m_nValue << endl;
    else
        cout << "Error!" << endl;
    return 0;
}
