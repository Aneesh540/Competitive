#include<iostream>
using namespace std;

struct Node{

    Node(int value, Node* ptr = nullptr):
    data(value), next(ptr) {}

    int data;
    Node* next;
};

class List{
    private:
        Node* head;

        void reverseUtil(Node* p){
            if(p == nullptr)
                return;
            
            // cout<<"calling @ = "<<p->data<<endl;
            reverseUtil(p->next);
            
            cout<<p->data<<", ";
        }
    
    public:
        List(): head(nullptr) {}

        void add_element(int value){
            // adding element at head of linked list
            head = new Node(value,head);
        }
    
        void print(){
            Node* cursor = head;
            
            while(cursor != nullptr){
                cout<<cursor->data<<", ";
                cursor = cursor->next;
            }cout<<endl;
        }

        void reverse_list_iterative(){
            Node* Previous = nullptr;
            Node* Current = head;
            Node* Next = head->next;

            while(Current != nullptr){
                cout<<"reversing in progress !! "<<endl;
                Current->next = Previous;
                Previous = Current;
                Current = Next;

                if(Next != nullptr)
                    Next = Next->next;
                    // varna Next->next kuch bhi nahi hoga
                    // aur program segmentation fault de dega
            }

            head = Previous;
        }

        void reverse_recursive(){
            // to make it 
            int i=0;
        }

        void reverse_print(){
            
            Node* cursor = head;
            cout<<"Recersive Reverse Printing : ";
            reverseUtil(cursor);
            cout<<endl;
        }
        


};


int main(){
    List list;

    list.add_element(3);
    list.add_element(31);
    list.add_element(45);
    list.add_element(87);

    list.print();
    list.reverse_list_iterative();

    list.print();
    list.reverse_print();
   
    list.print();
    

}