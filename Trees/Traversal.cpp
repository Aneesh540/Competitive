#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};


Node *createNewNode(int data){
    Node *newNode = new Node();

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


void insert(Node*& root, int value){
    
    if(root == NULL){
    
        root =  createNewNode(value);
    }
    
    else if(root->data < value){
        // insert right
        
        insert(root->right,value);
    }
    
    else{
        // insert left side
        insert(root->left,value);
    }
}


void preOrder(Node* root){

    if(root != NULL){
        cout<<root->data<<"-> ";
        preOrder(root->left);
        preOrder(root->right);

    }
}


void inOrder(Node* root){

    if(root != NULL){
    inOrder(root->left);
    cout<<root->data<<"-> ";
    inOrder(root->right);
    }
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

    insert(root_pointer, 4);
    insert(root_pointer, 2);
    insert(root_pointer, 7);
    insert(root_pointer, 9);
    insert(root_pointer, 3);
    insert(root_pointer, 1);

            //         4
            //        /  \
            //       /    \
            //       2     7
            //     /  \     \
            //    1    3     \
            //               9

    level_order_traversal(root_pointer);
    cout<<"\nPreorder traversal is :"<<endl;
    preOrder(root_pointer);


    cout<<endl;
    cout<<"\nInroder traversal is :"<<endl;
    inOrder(root_pointer);

}