#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this-> data = d;
        this-> left = NULL;
        this-> right = NULL;
    }
};

class binaryTree{
    Node* root;
    public:
    binaryTree(){
        root = NULL;
    }

    Node* buildTree(){
        cout << "Enter the data: " << endl;
        int data;
        cin >> data;
        
        root = new Node(data);

        if(data == -1){
            return NULL;
        }

        cout << "Enter  data for left of " << data << ": " << endl;
        root->left = buildTree();
        cout << "Enter  data for right of " << data << ": " << endl;
        root->right = buildTree();
        return root;

    }
};
int main(){
    binaryTree bt;
    bt.buildTree();

    return 0;
}