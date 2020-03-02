//用队列实现栈
#include <queue>
using namespace std;

// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        topval = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
       while(q1.size() > 1)
       {
           topval = q1.front();
           q1.pop();
           q2.push(topval);
       }
       int result = q1.front();
       q1.pop();
       queue<int> tmp = q1;
       q1 = q2;
       q2 = tmp;
       return result;
    }
    
    /** Get the top element. */
    int top() {
       return topval;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
private:    
    queue<int> q1;
    queue<int> q2;
    int topval;
};