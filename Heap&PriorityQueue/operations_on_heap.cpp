#include<iostream>
#include<vector>
using namespace std;

bool max_heapify(vector<int>& array, int rootNodeIndex){
    // check if left child exist
    // check if right child exist 
    // find index of maximum among child
    // compare root and (index of maximum among child) and update
    // if updated then apply recursion on that child i.e. max_heapify(array, child)
    // cout<<"running on - "<<rootNodeIndex<<endl;

    int heap_size = array.size();
    int largestIndex = rootNodeIndex;

    int leftChildIndex = 2*rootNodeIndex;
    int rightChildIndex = 2*rootNodeIndex + 1;
    // cout<<"-----> "<<rootNodeIndex<<" "<<leftChildIndex<<" "<<rightChildIndex<<endl;


    if(leftChildIndex < heap_size && array[leftChildIndex] > array[largestIndex]){
        // left child exist karta hai and uski value badi hai then update largest
        largestIndex = leftChildIndex;
    }

    if(rightChildIndex < heap_size && array[rightChildIndex] > array[largestIndex]){
        largestIndex = rightChildIndex;
    }

    if(largestIndex != rootNodeIndex){
        // kuch to change hua hai
        // cout<<"yup heapifying it ("<<
        // rootNodeIndex<<" "<<array[rootNodeIndex]<<")  ("<<largestIndex<<" "<<array[largestIndex]<<")\n\n*******"<<endl;

        int temp = array[largestIndex];
        array[largestIndex] = array[rootNodeIndex];
        array[rootNodeIndex] = temp;

        max_heapify(array,largestIndex);
        return true;

    }

    else { return false; }

    
    
}


void build_heap(vector<int>& array){

    int total_nodes = array.size();
    int leaf_nodes_starting = total_nodes/2;

    for(int i=leaf_nodes_starting; i>0; --i){
         max_heapify(array,i);
    }

}

void add_element(vector<int>& array, int value){

    array.push_back(value);

    int foo = (array.size()-1)/2; // nayi node ke parent se start kar rahe hai
    while(foo >= 1){
    // jab tak uss node se parent nahi aa jata

        int result = max_heapify(array,foo);
        cout<<"foo = "<<foo<<" "<<array[foo]<<" "<<result<<true<<endl;
        if(result == true){
            foo = foo/2;
        }

        else
            break;
        

    
    }


}



int main(){

    vector<int> v = {-1,1,4,6,7,8,9,10,12,15,17};

    build_heap(v);

     
    for(auto x:v){
        cout<<x<<" ";
    }cout<<endl;

    add_element(v,50);

    
    for(auto x:v){
        cout<<x<<" ";
    }cout<<endl;


}