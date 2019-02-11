#include<iostream>
#include<vector>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int value, Node* ptr = nullptr): data(value), next(ptr) {}
};


class Queue{

    private:
        Node* front;
        Node* rear;
        int size;
    
    public:
        Queue(): front(nullptr), rear(nullptr), size(0) {}

        void enqueue(int value){

            if(front == nullptr && rear == nullptr){
                front = rear = new  Node(value);
            }

            else{
                rear->next = new Node(value);
                rear = rear->next;
            }

            size++;
        }


        void dequeue(){
            
            if(front == nullptr)
                cout<<"Queue is empty"<<endl;
            
            else if(front->next == nullptr){
                // cout<<"dequing "<<rear->data<<endl;
                delete rear;
                
                rear = nullptr;
                front = nullptr;
                size--;
            }

            else{
            // cout<<"dequing "<<front->data<<endl;
            Node * temp = front;
            front = front->next;


            delete temp;
            size--;
            }

        }


        int getsize(){
            cout<<size<<endl;
            return size;
        }


        int top(){
            if (front == nullptr){
                // cout<<"Queue is empty "<<endl;
                return -9999;
            }

            // cout<<"top element = "<<front->data<<endl<<endl;
            return front->data;
        }

        bool isEmpty(){
            if(front == nullptr)
                return true;
            
            return false;
        }

};


class Stack{
    private:
        Queue q1;
        Queue q2;
        int size;
    
    public:
        Stack(): size(0) {}

        void push(int value){
            
            if(q1.isEmpty() == true)
                q1.enqueue(value);
            
            
            else{
                int intialSize = q1.getsize();

                q1.enqueue(value);

                for(int i=0; i<intialSize; ++i){
                    q1.enqueue(q1.top());
                    q1.dequeue();
                }
            }

            size++;
            
        }

        void pop(){
            
            if(q1.isEmpty() == true)
                cout<<"Stack is empty"<<endl;
            
            else{
                q1.dequeue();
                size--;
            }

            
        }


        int top(){
            if(q1.isEmpty() == true){
                cout<<"stack is empty"<<endl;
                return -9999;
            }

            else{
                cout<<"stack top = "<<q1.top()<<endl;
                return q1.top();
            }
        }

        int getsize(){
            cout<<"stack size == "<<size<<endl;
            return size;
        }
    

};



int main(){
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(17);
    // q.enqueue(34);
    q.getsize();

    q.dequeue();
    q.getsize();
    q.dequeue();
    q.top();
    q.dequeue();
    

    q.getsize();
    q.top();




    Stack s;
    s.getsize();
    s.push(1);
    s.push(2);
    s.getsize();
    s.top();
    s.pop();
    s.top();
    s.pop();
    s.top();
    s.pop();s.pop();
    s.getsize();
    s.push(2);
    s.getsize();
    s.top()
    ;
    


}