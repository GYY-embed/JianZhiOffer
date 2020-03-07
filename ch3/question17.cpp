//面试题17、合并两个排序的链表
#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

//合并链表
ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;
    
    ListNode *pMergedHead = NULL;

    if(pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }
    return pMergedHead;
}

ListNode *AddNode(ListNode *pListHead, int num)
{
    ListNode *Node = new (ListNode);
    Node->m_nValue = num;
    Node->m_pNext = pListHead;
    return Node;
}
void PrintList(ListNode *pListHead)
{
    ListNode *Node = pListHead;
    while(Node != NULL)
    {
//       cout << " OK ";
        cout << Node->m_nValue << "\t" ;
        Node = Node->m_pNext;
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    //构建有序链表1
    ListNode *pHead1 = new (ListNode);
    pHead1->m_nValue = 9;
    pHead1->m_pNext = NULL;
    pHead1 = AddNode(pHead1, 8);
    pHead1 = AddNode(pHead1, 5);
    pHead1 = AddNode(pHead1, 3);
    pHead1 = AddNode(pHead1, 2);
    PrintList(pHead1);
    //构建有序链表2
    ListNode *pHead2 = new (ListNode);
    pHead2->m_nValue = 7;
    pHead2->m_pNext = NULL;
    pHead2 = AddNode(pHead2, 6);
    pHead2 = AddNode(pHead2, 5);
    pHead2 = AddNode(pHead2, 2);
    pHead2 = AddNode(pHead2, 1);
    PrintList(pHead2);

    ListNode *pMergedHead = new (ListNode);
    pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);
    return 0;
}