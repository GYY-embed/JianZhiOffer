//判断链表是否有环
#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

 bool hasCycle(ListNode *head) 
 {
    ListNode* faster{ head };  
	ListNode* slower{ head };  

	if (head == NULL)  
		return false;

	while (faster != NULL && faster->m_pNext != NULL)
	{
		faster = faster->m_pNext->m_pNext;  
		slower = slower->m_pNext;  
		if (faster == slower)  
			return true;  
	}
	return false;
 }

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
