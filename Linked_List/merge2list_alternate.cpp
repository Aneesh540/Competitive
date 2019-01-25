#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};


Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->link = NULL;

    return newNode;
}


void insert(Node*& root, int value){

    Node* new_node = createNode(value);
    new_node->link = root;
    root = new_node;

}

void print(Node* root){
    
    if(root == NULL)
        cout<<"NULL"<<endl;

    while(root != NULL){
        cout<<root->data<<", ";
        root = root->link;
    }cout<<endl;
}

inline void append(Node*& node1, Node*& node2){
    
    Node* temp1 = node1->link;
    Node* temp2 = node2->link;
    
    node1->link = node2;
    
    node2->link = temp1;
    
    node2 = temp2;
}



void merge(Node* root1, Node*& root2){
    
    Node* dup_root1 = root1;
    
    while(1){
               
        append(dup_root1,root2);
        dup_root1 = dup_root1->link->link;

        if(dup_root1 == NULL)
            break;
        if(root2 == NULL)
            break;
        
    }
    
}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;

    insert(root1,1);
    insert(root1,11);
    insert(root1,12);
    insert(root1,41);
    insert(root1,9);

    insert(root2,51);
    insert(root2,3);
    insert(root2,21);
    insert(root2,69);
    insert(root2,69);
    insert(root2,123);
    insert(root2,456);

    print(root1);
    print(root2);
    
    
    merge(root1,root2);
    
    print(root1);
    print(root2);




}