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

// Level order traversal
void levelorder(Node *root)
{
    queue<Node *> q;
    Node *temp;
    q.push(root);
    q.push(NULL);
    //TODO: try with .back() method and also try to figure why .pop() directly doesn't work.
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
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

// Delete a node in BST
Node *deleteNode(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    // if the data is less than root, then search in left subtree
    if (d < root->data)
    {
        root->left = deleteNode(root->left, d);
    }
    // if the data is greater than root, then search in right subtree
    else if (d > root->data)
    {
        root->right = deleteNode(root->right, d);
    }
    // if the data is equal to root, then delete this node
    else
    {
        // if node to be deleted has no children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // if node to be deleted has only one child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // if node to be deleted has two children
        else
        {
            Node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main(){
    Node* root = NULL;
    cout << "Enter data to insert in BST: " << endl;
    takeInput(root);

    cout<<"Level Order Traversal: "<<endl;
    levelorder(root);
    
    cout << "\nInorder"<<endl;
    inorder(root);

    cout << "\nEnter data to delete: " << endl;
    int d;
    cin >> d;
    root = deleteNode(root, d);

    cout << "Inorder" << endl;
    inorder(root);


    return 0;
}
