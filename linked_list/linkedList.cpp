#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    
    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
    Node* head;
    Node* tail;
    public:
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    //Inserting new element at head
    void insertAtHead(int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        
        temp->next = head;
        head = temp;
    }

    //Inserting new element at tail
    void insertAtTail(int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        tail->next = temp;
        tail = temp;
    }

    //Inserting an element in the middle 
    void insertAtMiddle(int position, int d){
        Node* temp = new Node(d);
        if(head == NULL){
            cout << "Invalid operation"<<endl;
        }
        /*
        TODO: Implement a count function and check if position is out of range i.e Position > Number of Nodes
        */
        Node* curr = head;
        int start = 1;
        while(start < (position-1)){
            curr = curr->next;
            start++;
        }
        temp->next = curr->next;
        curr->next = temp;

    }

    //Printing the list
    void printList(){
        Node* curr = head;
        while(curr!= NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};

int main(){

    LinkedList ll;
    ll.insertAtHead(10);
    ll.insertAtHead(20);
    ll.insertAtHead(30);
    ll.printList();
    
    ll.insertAtTail(60);
    ll.insertAtTail(70);
    ll.insertAtTail(80);
    ll.printList();

    return 0;
}