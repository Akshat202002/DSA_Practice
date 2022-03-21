#include<iostream>
#include<queue>
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

//Postorder Traversal(LRN)
void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

//Levelorder Traversal(LRN)
void levelorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){

        //TODO: try with .back() method and also try to figure why .pop() directly doesn't work.
        Node* temp = q.front();
        cout << temp-> data << " ";
        q.pop();
        if(temp->left)
            q.push(temp-> left);
        if(temp->right)
            q.push(temp-> right);
    }

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

    cout<<"Postorder Traversal: " << endl;
    postorder(root);
    cout << endl;

    cout << "Levelorder traversal: " << endl;
    levelorder(root);
    cout << endl;

    return 0;
}