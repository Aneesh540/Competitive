// Given two linked lists, insert nodes of second list into first 
// list at alternate positions of first list.
// For example, if first list is 5->7->17->13->11 and 
// second is 12->10->2->4->6, the first list should 
// become 5->12->7->10->17->2->13->4->11->6 
// and second list should become empty. The nodes of second list 
// should only be inserted when there are positions available. 
// For example, if first list is 1->2->3 and second list is 4->5->6->7->8
// then, first list should become 1->4->2->5->3->6 and second list to 7->8.

// Use of extra space is not allowed 
// (Not allowed to create additional nodes), 
// i.e., insertion must be done in-place. time complexity is O(n) 
// where n is number of nodes in first list.


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