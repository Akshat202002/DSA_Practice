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

//Building a tree
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

//Inorder Traversal(LNR)
void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

//Preorder Traversal(NLR)
void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }
    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}


int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout<<"Inorder Traversal: " << endl;
    inorder(root);
    cout << endl;

    cout<<"Preorder Traversal: " << endl;
    preorder(root);
    cout << endl;

    return 0;
}