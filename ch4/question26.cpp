//面试题26：复杂链表的复制
#include <iostream>
#include <map>

using namespace std;

//复杂链表节点，除了有指向下一个节点的指针外还有一个指向任意位置的指针
struct ComplexListNode
{
    int m_nValue;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
};
/**************************方法1:不使用辅助空间**********************************/
//复制节点，并连接到原节点的后面
void CloneNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while(pNode != NULL)
    {
        ComplexListNode *pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = NULL;
        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;
    }
}
//设置复制节点的m_pSibling
void ConnectSiblingNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while(pNode != NULL)
    {
        ComplexListNode *pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != NULL)
        {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        pNode = pCloned->m_pNext;
    }
}
//将长链表拆分成两个链表
ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    ComplexListNode *pClonedHead = NULL;
    ComplexListNode *pClonedNode = NULL;

    if(pNode != NULL)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    while(pNode != NULL)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pClonedHead;
}

ComplexListNode *Clone1(ComplexListNode *pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

/**************************方法2:使用辅助空间**********************************/
ComplexListNode *Clone2(ComplexListNode *pHead)
{
    if(pHead == NULL)
        return NULL;
    map<ComplexListNode*, ComplexListNode*> nodeMap;

    ComplexListNode *currNode = pHead;
    ComplexListNode *newNode = NULL, *preNode = NULL, *newHead = NULL;

    //首先复制原链表的普通链表指针域，一次遍历即可完成
    while(currNode != NULL)
    {
        newNode = new ComplexListNode();
        newNode->m_nValue = currNode->m_nValue;
        newNode->m_pNext = NULL;
        newNode->m_pSibling = NULL;
        nodeMap[currNode] = newNode;
        currNode = currNode->m_pNext;
        if(preNode == NULL)
        {
            newHead = newNode;
        }
        else
        {
            preNode->m_pNext = newNode;
        }
        preNode = newNode;
    }

    //接着复制随机指针
    currNode = pHead;
    newNode = newHead;
    while(currNode != NULL && newNode != NULL)
    {
        ComplexListNode *randNode = currNode->m_pSibling;
        ComplexListNode *newRandNode = nodeMap[randNode];
        newNode->m_pSibling = newRandNode;
        
        //链表同步移动
        currNode = currNode->m_pNext;
        newNode = newNode->m_pNext;
    }
    return newHead;
}

int main(int argc, char const *argv[])
{

    /* code */
    return 0;
}
