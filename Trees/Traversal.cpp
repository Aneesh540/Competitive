#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *insert(Node *root, int data)
{

    if (root == NULL)
        root = createNode(data);
    
    else if (data < root->data)
        root->left = insert(root->left, data);
    
    else
        root->right = insert(root->right, data);
    
    
    return root;
}

void level_order_traversal(Node* root){
    // space & time complexity


    if(root == NULL) return;

    queue<Node*> Q;
    Q.push(root);

    while(! Q.empty()){

        Node* current = Q.front();
        Q.pop();

        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        cout<<current->data<<" -> ";

    }
    cout<<endl;

}

int main(){

    Node *root_pointer = NULL;

    root_pointer = insert(root_pointer, 4);
    root_pointer = insert(root_pointer, 2);
    root_pointer = insert(root_pointer, 7);
    root_pointer = insert(root_pointer, 9);
    root_pointer = insert(root_pointer, 3);
    root_pointer = insert(root_pointer, 1);

    level_order_traversal(root_pointer);
}