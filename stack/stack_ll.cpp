// Implementation of stack using linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class Stack
{
    Node *head; // head is like top of stack
public:
    Stack()
    {
        head = NULL;
    }
    // we are always inserting and removing at head position
    void push(int d)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int d = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        return d;
    }
    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.print();
    cout << s.pop() << endl;
    s.print();
    cout << s.top() << endl;
    return 0;
}
