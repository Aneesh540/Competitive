#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;

    return newNode;

}


int Height(Node* root){

    if(root == NULL)
        return 0;
    
    return max(Height(root->left),Height(root->right)) + 1;
}


int main(void){

    Node* root = createNode(4);
    root->right = createNode(5);
    root->right->right = createNode(8);
    
    root->right->right->left = createNode(33);
    root->right->right->right = createNode(39);
        root->right->right->right->right = createNode(39);


    root->left = createNode(1);
    root->left->right = createNode(13);
    root->left->left = createNode(13);

    cout<<Height(root);


}