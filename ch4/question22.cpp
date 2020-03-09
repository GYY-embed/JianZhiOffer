//面试题22、栈的压入、弹出序列
#include <iostream>
#include <stack>

using namespace std;

bool IsPopOrder(const int *pPush, const int *pPop, int length)
{
    bool bPossible = false;
    if(pPush != NULL && pPop != NULL && length > 0)
    {
        const int *pNextPush = pPush;
        const int *pNextPop = pPop;

        stack<int> dataStack;
        while(pNextPop - pPop < length)
        {
            while(dataStack.empty() || dataStack.top() != * pNextPop)
            {
                if(pNextPush - pPush == length)
                    break;
                dataStack.push(*pNextPush);
                pNextPush++;
            }

            if(dataStack.top() != *pNextPop)
                break;
            dataStack.pop();
            pNextPop++;
        }
        if(dataStack.empty() && pNextPop - pPop == length)
            bPossible = true;
    }
    return bPossible;
}
int main(int argc, char const *argv[])
{
    int push1[5] = {1, 2, 3, 4, 5};
    int pop1[5] = {4, 5, 3, 2, 1};
    int pop2[5] = {4, 3, 5, 1, 2};
    cout << IsPopOrder(push1, pop1, 5) << endl;
    cout << IsPopOrder(push1, pop2, 5) << endl;
    return 0;
}

