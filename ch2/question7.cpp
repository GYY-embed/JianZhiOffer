#include <iostream>
#include <stack>

using namespace std;

template<typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size() == 0)
    {
        while(stack1.size() >0)
        {
            T &data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if(stack2.size() == 0)
        throw new exception("Queue is empty");
    
    T head = stack2.top();
    stack2.pop();

    return head;
}

int main(int argc, char const *argv[])
{
    CQueue<int> cq;
    cq.appendTail(1);
    cq.appendTail(3);
    cq.appendTail(5);
    cq.appendTail(7);
    cout << cq.deleteHead() << endl;
    cout << cq.deleteHead() << endl;
    cout << cq.deleteHead() << endl;
    cout << cq.deleteHead() << endl;
    cout << cq.deleteHead() << endl;
    return 0;
}

