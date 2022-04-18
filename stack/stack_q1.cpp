// Implementation of stack using single queue
#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q;

public:
    void push(int d)
    {
        // push at tail
        q.push(d);
        // move all elements from q to q1
        for (int i = 0; i < q.size() - 1; i++)
        {
            // push at tail
            q.push(q.front());
            // remove from front
            q.pop();
        }
    }

    int pop()
    {
        // check if stack is empty
        if (q.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        // store the top element
        int d = q.front();
        // remove the top element
        q.pop();
        return d;
    }
    int top()
    {
        if (q.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }
    bool isEmpty()
    {
        return q.empty();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;

    return 0;
}