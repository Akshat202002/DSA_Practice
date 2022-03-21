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



Node* insertBST(Node* &root, int d){
    //Base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    //Insertion in right
    if(d > root-> data){
        root-> right = insertBST(root->right, d);
    }
    else{
        //Insertion in left
        root-> left = insertBST(root->left, d);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;
    while(data!= -1){
        root = insertBST(root, data);
        cin >> data;
    }
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

int main(){
    Node* root = NULL;
    cout << "Enter data to insert in BST: " << endl;
    takeInput(root);

    cout<<"Level Order Traversal: "<<endl;
    levelorder(root);
    
    cout << "\nInorder"<<endl;
    inorder(root);


    return 0;
}
