// Implementation of stack using two queues
#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int d)
    {
        // pushing element at tail of q1
        q1.push(d);
    }
    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        // move all elements from q1 to q2
        while (q1.size() > 1)
        {
            // pushing element at tail of q2
            q2.push(q1.front());
            // remove from front
            q1.pop();
        }

        // store the top element
        int d = q1.front();
        // remove the top element
        q1.pop();
        // move all elements from q2 to q1
        swap(q1, q2);
        return d;
    }
    // top function
    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int d = q1.front();
            q1.pop();
            q2.push(d);
            swap(q1, q2);
            return d;
        }
    }
    bool isEmpty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;

    return 0;
}