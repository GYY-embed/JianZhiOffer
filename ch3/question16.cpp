//面试题16：反转链表
#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

ListNode *ReverseLeist(ListNode *pHead)
{
    ListNode *preNode = NULL, *currNode = pHead, *rearNode = NULL;
    if(pHead == NULL || pHead->m_pNext == NULL)
        return pHead;
    while(currNode != NULL)
    {
        ListNode *pNext = currNode->m_pNext;
        if(pNext == NULL)
        {
            //cout << "Last:" << currNode->m_nValue << endl;
            currNode->m_pNext = preNode;
            rearNode = currNode;
        }    
        currNode->m_pNext = preNode;
        preNode = currNode;
        currNode = pNext;
        //cout << "OK " << endl;
    }
    return rearNode;
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
    ListNode *pHead = new (ListNode);
    pHead->m_nValue = 3;
    pHead->m_pNext = NULL;
    pHead = AddNode(pHead, 4);
    pHead = AddNode(pHead, 5);
    pHead = AddNode(pHead, 8);
    pHead = AddNode(pHead, 9);
    PrintList(pHead);
    pHead = ReverseLeist(pHead);
    PrintList(pHead);
    return 0;
}

