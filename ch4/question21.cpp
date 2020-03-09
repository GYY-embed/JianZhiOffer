//面试题21、包含min函数的栈
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template<typename T> class myStack
{
public:
    myStack(void) = default;
    ~myStack(void) = default;

    void Push(const T& data);
    T Top(void);
    T Min(void);
    void pop(void);
private:
    stack<T> DataStack;
    stack<T> AssistStack;
    T min = 0;
};

template<typename T> void myStack<T>::Push(const T& data)
{
    if(DataStack.size() == 0 || data < min)
    {
        min = data;
    }
    DataStack.push(data);
    AssistStack.push(min);
}

template<typename T> T myStack<T>::Top(void)
{
    if(DataStack.size() != 0)
    {
        return DataStack.top();
    }
}

template<typename T> T myStack<T>::Min(void)
{
    return AssistStack.top();
}

template<typename T> void myStack<T>::pop(void)
{
    DataStack.pop();
    AssistStack.pop();
}

int main(int argc, char const *argv[])
{
    myStack<int> mStack;
    mStack.Push(2);
    cout << mStack.Min() << endl;
    mStack.Push(1);
    cout << mStack.Min() << endl;
    mStack.Push(3);
    cout << mStack.Min() << endl;
    mStack.Push(4);
    cout << mStack.Min() << endl;
    mStack.Push(0);
    cout << mStack.Min() << endl;

    mStack.pop();
    cout << mStack.Min() << endl;
    return 0;
}
