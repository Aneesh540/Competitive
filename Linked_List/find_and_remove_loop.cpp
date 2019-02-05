#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
        Node(int value, Node* ptr = nullptr): data(value), next(ptr) {}

};


class LinkedList{
    
    private:
        Node* head;
    
    public:
        LinkedList(): head(nullptr) {}

        void push_front(int value){
            head = new Node(value, head);
            
        }

        void print(){
            
            Node* iter= head;
            while(iter != nullptr){
                cout<<iter->data<<", ";
                iter = iter->next;
            }cout<<endl;
            
        }

        Node* isCyclePresent(){
            Node* rabbit = head;    // rabbit will move 2 times the tortoise
            Node* tortoise = head;

            while(rabbit != nullptr || tortoise != nullptr){

                tortoise = tortoise->next;
                rabbit = rabbit->next;

                // if rabbit is nullptr then cycle is not present 
                // ALSO WE CANNOT MOVE RABBIT 2 STEPS BECAUSE IT IS ALREADY AT nullptr
                if(rabbit == nullptr){
                    cout<<"not present "<<endl;
                    return nullptr;
                    }
                
                else if(rabbit != nullptr)
                    rabbit = rabbit->next;
                
                if(rabbit == tortoise){// if they both meet then cycle is present
                    cout<<"present "<<endl;
                    return tortoise;
                }

            }
        }

        void createCycle(int nodeToConnect){
            // this method will connect the last node->next (which is nullptr initially)
            // to the specified node's pointer 

            Node* cursor;
            Node* specifiedNode = head;
            

            for(int i=1; i<nodeToConnect; ++i){
                specifiedNode = specifiedNode->next;
            }

            cursor = specifiedNode;
            while(cursor->next != nullptr){
                cursor = cursor->next;
            }

            cout<<"creating cycle @ "<<specifiedNode->data<<endl;
            cursor->next = specifiedNode;

        }

        Node* headOfCycle(){
            Node* a = head;
            Node* b = isCyclePresent();

            if(b == nullptr){
                cout<<"cycle not present"<<endl;
                return nullptr;
            }

            while(1){

                if(a == b)
                    break;
                
                a = a->next;
                b = b->next;
            }

            cout<<"starting point = "<<a->data<<endl;
            return a;
        }

};



int main(){

    LinkedList mylist;
    mylist.push_front(9);
    mylist.push_front(91);
    mylist.push_front(29);
    mylist.push_front(11);
    mylist.push_front(77);

    mylist.isCyclePresent();

    mylist.createCycle(4);

    mylist.isCyclePresent();
    mylist.headOfCycle();


}