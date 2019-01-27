#include<iostream>

class SinglyLinkedList{
    private:
        int data;
        SinglyLinkedList* next;
    
    public:
        SinglyLinkedList(int value = 0, SinglyLinkedList* ptr = NULL):
            data(value), next(ptr) {}
};


struct LinkedList{
    LinkedList(int value, LinkedList* ptr):
        data(value), next(ptr);

    int data;
    LinkedList* next;

};


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