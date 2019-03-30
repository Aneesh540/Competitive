#include<iostream>
#include<algorithm>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

}

int findingMin(Node *root, int value)
{
    int answer = root->data;

    while(1){

        if(root->data == value){
            answer = max(answer,root->data);
            return answer;
        }

        else if(root->data < value){
            root = root->right;
            answer = max(answer,root->data);
        }

        else if (root->data > value)
        {
            root = root->left;
            answer = max(answer, root->data);
        }
    }

    

}

void insert(Node*& root, int value){
    
    if(root == NULL){
    
        root =  createNode(value);
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

bool isPresent(Node* root, int data){

    if(root == NULL)return false;

    if (root->data == data) return true;

    else if(root->data < data)// data bada hai 
        isPresent(root->right,data);

    else
        isPresent(root->left,data);    
}

int find_min_recursive(Node* root){

    if(root == NULL)
        return -1;

    if(root->left == NULL)
        return root->data;

    else{
        find_min_recursive(root->left);
    }        
}

int find_max_iterative(Node* root){
    
    if(root == NULL)
        return -1;

    
    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
        
}

int height(Node* root){
    if(root == NULL)
        return -1;

    if(root->left == NULL && root->right==NULL)
        return 0;

    else{
        return max(height(root->left), height(root->right)) + 1;
    }        
}


int main(){

    Node* root_pointer = NULL;

    insert(root_pointer,15);
    insert(root_pointer,10);
    insert(root_pointer,20);
    insert(root_pointer,25);
    insert(root_pointer,45);
    insert(root_pointer,5);
    insert(root_pointer,13);
    insert(root_pointer,18);
    insert(root_pointer,17) ;   
    insert(root_pointer,23);
    insert(root_pointer,24);
    //  cout << isPresent(root_pointer,2) << endl;
    //  cout << isPresent(root_pointer, 20) << endl;
    //  cout << isPresent(root_pointer, 25) << endl;
    

    //  cout<<"*********"<<endl;
    //  cout<<find_min_recursive(root_pointer)<<endl;
    //  cout<<find_max_iterative(root_pointer)<<endl;

    //  cout<<"************"<<endl;

    //  cout<<height(root_pointer)<<endl;
    // cout<<max(34,12);
    cout<<findingMin(root_pointer,15);


}