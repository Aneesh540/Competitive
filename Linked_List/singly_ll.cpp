#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->link = NULL;
    newNode->data = value;
}

void insert(Node* head, int value){

    Node* move = head;
    while(move->link != NULL){
        move = move->link;
    }


    // creating a new node 
    Node* nd = createNode(value);
    move->link = nd; // link list ke last wala part  (NULL) ko update kara 

}


void print(Node* head){

    Node* temp = head;

    while(temp != NULL){
        
        cout<<temp->data<<endl;
        temp = temp->link;
    }


}

void deleteNode(Node* head, int value){
    
    Node* prev = head;
    Node* current = head->link;

    while(current->link != NULL){

        if(current->data != value){
            current = current->link;
            prev = prev->link;
        }

        else if(current->data == value){
            // prev->link = current->link;
            Node* var2 = current->link
            
            free(current);

        }

    }
}



void delete2(Node* head, int value){
    Node* prev = head;

    while(prev->link != NULL){
       
        Node* next = prev->link;

        if(next->data == value){
            prev->link = next->link;
            free(next);

        }
    }
}

int main(){

    Node* head;
    head = NULL;

    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = 12;
    newNode->link = NULL;

    head = newNode;

    insert(456);
    insert(555);
    insert(123);
    print(head);



}