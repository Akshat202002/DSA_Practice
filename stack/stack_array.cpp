// Implementation of stack using array
#include <iostream>
using namespace std;
class Stack
{
    int *arr;
    int top;
    int capacity;

public:
    Stack(int cap)
    {
        capacity = cap;
        top = -1;
        arr = new int[capacity];
    }
    void push(int d)
    {
        if (top == capacity - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = d;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top--];
    }
    // top function
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// main function
int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.print();
    cout << "Popped element: " << s.pop() << endl;
    s.print();
    cout << "Popped element: " << s.pop() << endl;
    s.print();
    cout << "Element at top: " << s.peek() << endl;
    s.print();
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    s.print();
    return 0;
}