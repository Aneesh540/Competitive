#include<iostream>
#include<vector>
using namespace std;

void max_heapify(vector<int>& array, int rootNodeIndex){
    // check if left child exist
    // check if right child exist 
    // find index of maximum among child
    // compare root and (index of maximum among child) and update
    // if updated then apply recursion on that child i.e. max_heapify(array, child)
    cout<<"running on - "<<rootNodeIndex<<endl;

    int heap_size = array.size();
    int largestIndex = rootNodeIndex;

    int leftChildIndex = 2*rootNodeIndex;
    int rightChildIndex = 2*rootNodeIndex + 1;
    cout<<"-----> "<<rootNodeIndex<<" "<<leftChildIndex<<" "<<rightChildIndex<<endl;


    if(leftChildIndex < heap_size && array[leftChildIndex] > array[largestIndex]){
        // left child exist karta hai and uski value badi hai then update largest
        largestIndex = leftChildIndex;
    }

    if(rightChildIndex < heap_size && array[rightChildIndex] > array[largestIndex]){
        largestIndex = rightChildIndex;
    }

    if(largestIndex != rootNodeIndex){
        // kuch to change hua hai
        cout<<"yup heapifying it ("<<
        rootNodeIndex<<" "<<array[rootNodeIndex]<<")  ("<<largestIndex<<" "<<array[largestIndex]<<")\n\n*******"<<endl;

        int temp = array[largestIndex];
        array[largestIndex] = array[rootNodeIndex];
        array[rootNodeIndex] = temp;

        max_heapify(array,largestIndex);

    }

    else{
        cout<<"kuch nahi hua !!! \n\n******"<<endl;
    }
    
}





int main(){

    vector<int> v = {-1,1,4,6,7,8,9,10,12,15,17};

                /*         1
                //        / \
                //       /   \
                //      4     6
                //     / \   / \
                //    7   8  9  10
                //   /\    \
                //   12 15  \
                            17
                */

    int nonLeaf = v.size()/2;

    for(int i=nonLeaf; i>0; --i){
        cout<<"************ "<<i<<" == "<<endl;
        max_heapify(v,i);
    }


    for(auto x:v){
        cout<<x<<" ";
    }cout<<endl;

}