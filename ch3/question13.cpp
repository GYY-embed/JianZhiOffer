//面试题12、在O(1) 的时间删除链表节点
#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

void DeleteNode(ListNode **pListHead, ListNode *pToBeDelete)
{
    if(!pListHead || pToBeDelete)
        return;
    //要删除的节点不是尾节点
    if(pToBeDelete->m_pNext != NULL)
    {
        ListNode *pNext = pToBeDelete->m_pNext;
        pToBeDelete->m_nValue = pNext->m_nValue;
        pToBeDelete->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = NULL;
    }
    //如果链表只有一个节点，删除头结点
    else if(*pListHead == pToBeDelete)
    {
        delete pToBeDelete;
        pToBeDelete = NULL;
        *pListHead = NULL;
    }
    //链表中有多个节点，删除尾节点
    else
    {
        ListNode *pNode = *pListHead;
        while(pNode->m_pNext != pToBeDelete)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = NULL;
        delete pToBeDelete;
        pToBeDelete = NULL;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
