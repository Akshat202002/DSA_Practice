#include <iostream>
// creating a node
class node
{
public:
    int data;
    node *next;
};
// creating a class
class linklist
{
private:
    node *head;

public:
    linklist()
    {
        head = NULL;
    }
    // inserting a node at the end of the list
    void insert(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = temp;
        }
    }
    // insert a node at the beginning of the list
    void insert_begin(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    // insert a node at a given position
    void insert_pos(int data, int pos)
    {
        node *temp = new node;
        temp->data = data;
        node *current = head;
        if(pos==1){
            insert_begin(data);
            return;
        }
        int i = 1;
        while (i < pos - 1)
        {
            current = current->next;
            i++;
        }
        temp->next = current->next;
        current->next = temp;
    }

    // delete a node from the end of the list
    void delete_end()
    {
        node *current = head;
        node *prev = NULL;
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        delete current;
    }
    // delete a node from the beginning of the list
    void delete_begin()
    {
        node *current = head;
        head = current->next;
        delete current;
    }
    // delete a node from a given position
    void delete_pos(int pos)
    {
        node *current = head;
        node *prev = NULL;
        int i = 1;
        while (i < pos - 1)
        {
            prev = current;
            current = current->next;
            i++;
        }
        prev->next = current->next;
        delete current;
    }
    // print the list
    void print()
    {
        node *current = head;
        while (current != NULL)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // return the size of the list
    int size()
    {
        node *current = head;
        int i = 0;
        while (current != NULL)
        {
            i++;
            current = current->next;
        }
        return i;
    }
    // return the data at a given position
    int at(int pos)
    {
        node *current = head;
        int i = 1;
        while (i < pos)
        {
            current = current->next;
            i++;
        }
        return current->data;
    }
    // reverse the list
    void reverse()
    {
        node *current = head;
        node *prev = NULL;
        node *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};
int main()
{
    // creating a list
    linklist l;
    // inserting elements in the list
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    // printing the list
    l.print();
}
