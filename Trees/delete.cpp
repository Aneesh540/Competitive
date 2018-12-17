#include<iostream>
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
    {
        root = createNode(data);
    }

    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }

    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* find_max_iterative(Node *root)
{

    if (root == NULL)
        return NULL;

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

Node* delete_node(Node* root, int value){

    if(root = NULL) return root;

    else if(value < root->data){
        // i.e. value may be present at left of root
        root->left = delete_node(root->left,value);

        // since after deletion address of root->left may change
        // so new return value is to be updated
    }

    else if(value > root->data){
        root->right = delete_node(root->right,value);

    }

    else{ // we have find the node to be deleted

        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            return root;
            // object in root is deleted now it become dangling pointer
            // but root still contain address of that object
            // so we set root = NULL 
             
        }

        else if(root->left == NULL){
            // iska child ka address iske parent ko de doo
            // root->left = delete_node() me root->left iska parent hai
            // so delete_node mei se return hoga iske right child ka address

            Node* temp = root->right;

            delete root;
            root = NULL;

            return temp;
        }


    else if(root->right == NULL){

        Node *temp = root->left;

        delete root;
        root = NULL;

        return temp;
    }

    // NODE WITH 2 CHILDRENS
    else{
        // find max in right sub tree
        // change value of this node to right me sabse max value
        // delete that node 
        // upadate root->right ki value after deletion

        Node* maxRightSubTree = find_max_iterative(root->right);

        root->data = maxRightSubTree->data;
        root->right = delete_node(root->right,maxRightSubTree->data);

    }   

    }

}



int main(){

    Node *root_pointer = NULL;

    root_pointer = insert(root_pointer, 15);
    root_pointer = insert(root_pointer, 10);
    root_pointer = insert(root_pointer, 20);
    root_pointer = insert(root_pointer, 25);
    root_pointer = insert(root_pointer, 45);

   
}