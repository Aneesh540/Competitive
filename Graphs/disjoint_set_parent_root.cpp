#include<iostream>
#include<vector>
using namespace std;

int root(vector<int>& arr, int node){
    // return root node of the given element

    if(arr[node] == node){ // i.e. the element itself is root 
        return node;
    }

    else{
        return root(arr,arr[node]);
    }

}


bool Find(vector<int>& v, int a, int b){

    if(root(v,a) == root(v,b)){
        return true;
    }

    else{
        return false;
    }
}


void Union(vector<int>& v, int a, int b){
    // second element niche jayega first ke

    int rootA = root(v,a);
    int rootB = root(v,b);

    v[rootB] = rootA;       // self explanatory
}


int main(){
   
   
    
}