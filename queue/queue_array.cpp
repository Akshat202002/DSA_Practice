// Implementing Queue using Array
#include <iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int *arr;
    // Queue using array
public:
    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    void enqueue(int d)
    {
        if (rear == -1)
        {
            rear = 0;
            front = 0;
            arr[rear] = d;
        }
        else
        {
            rear++;
            arr[rear] = d;
        }
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            int d = arr[front];
            front++;
            return d;
        }
    }

    int front_element()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int rear_element()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    int length()
    {
        return (rear - front + 1);
    }

    void print()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.print();
    cout << "Element at front end: " << q.front_element() << endl;
    cout << "Element at rear end: " << q.rear_element() << endl;
    q.isEmpty();
    cout << "Length of queue: " << q.length() << endl;
    return 0;
}