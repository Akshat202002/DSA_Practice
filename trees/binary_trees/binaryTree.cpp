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

Node* buildTree(Node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter  data for left of " << data << ": " << endl;
    root->left = buildTree(root-> left);
    cout << "Enter  data for right of " << data << ": " << endl;
    root->right = buildTree(root-> right);
    return root;

}

int main(){
    Node* root = NULL;
    buildTree(tree);

    return 0;
}