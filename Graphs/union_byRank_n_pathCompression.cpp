#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int root(vector<int>& vec, int node){

    if(vec[node] < 0)
        return node;


    int rootOfNode = root(vec, vec[node]);
    vec[node] = rootOfNode;

    return rootOfNode;
    
}


void print(vector<int>& vec){

    for(auto x:vec){
        cout<<x<<", ";
    }
    cout<<endl;
}

void UnionByRank(vector<int>& vec, int a, int b){

    int rootA = root(vec,a);
    int rootB = root(vec,b);

    int rankA = abs(vec[rootA]);
    int rankB = abs(vec[rootB]);


    if(rootA != rootB){

    if(rankA > rankB){
        // 'b' will become child of 'a',
        vec[rootA] += vec[rootB];   // updating total element in a
        vec[rootB] = rootA;         // make b's root parent as that of 'a'
    }
    
    else{
        vec[rootB] += vec[rootA];   // updating total element in b
        vec[rootA] = rootB;         // make a's root parent as that of 'b'
        }
    }


}


int FindPathCompression(vector<int> vec, int a){
    int rootA  = root(vec, a);

    vec[a] = rootA;

    return 


}

int main(){

    vector<int> v(4,-1);

    cout<<root(v,4)<<root(v,3)<<endl;

    UnionByRank(v,3,2);
        print(v);

    UnionByRank(v,1,3);
        print(v);

    UnionByRank(v,1,2);

    print(v);


    for(int i=0; i<5;++i){
        cout<<root(v,i)<<endl;
    }



}