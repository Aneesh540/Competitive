#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    // nullptr is the best practise over NULL or 0
        Node(int value = 0, Node* ptr = nullptr):
            data(value), next(ptr) {}
};


struct LinkedList{
    LinkedList(int value = 0, LinkedList* ptr = nullptr):
        data(value), next(ptr) {}

    int data;
    LinkedList* next;

};


class List{
    private:
        Node* head;
        Node* cursor;
    
    public:
        List(): head(nullptr), cursor(nullptr) {}
        List(const vector<int>& v);
        List(const List& lst);

        void push_front(int value){

            if(head == nullptr){
                // create a new list 
                cursor = head = new Node(value,head);
            }

            else{
                // append at front 
                head = new Node(value, head);
            }
        }
        
        int get_element(){
            return cursor->data; 
        }

        // convert this void return type to bool
        void advance() {cursor = cursor->next; }
        
        void print(){
            
            Node* iter= head;
            while(iter != nullptr){
                cout<<iter->data<<", ";
                iter = iter->next;
            }cout<<endl;
            
        }

        void delete_element(int value){
            Node* iter = head;

            if(head->data == value){
                head = head->next;
                delete iter;
                return;
            }

            while(iter->next != nullptr){// jab tak end element par nahi pauch gaya ho
                
                if(iter->next->data == value)    
                    break;
                

                iter = iter->next;
            }

            if(iter != nullptr){// iter is currently pointing to node before the delete node
                Node* nodeToDelete = iter->next;
                iter->next = nodeToDelete->next;

                delete nodeToDelete;
                cout<<"Deleted !"<<endl;

            }

            else{
                cout<<"element not found"<<endl;
            }
        }

        ~List(){
            for(cursor = head; cursor != nullptr; ){
                cursor = cursor->next;
                delete head;
                head = cursor;
            }
        }

};


int main(){

    List mylist;
    mylist.push_front(9);
    mylist.push_front(91);
    mylist.push_front(29);
    mylist.push_front(11);
    mylist.push_front(77);

    mylist.print();

    mylist.delete_element(91);
    mylist.delete_element(77);
    mylist.delete_element(9);

    mylist.print();

// getLength(){
//     if(root == nullptr)
//         return 0 
//     else:
//         return 1 + getLength(root->next);
// }


}