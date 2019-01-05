#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int root(vector<int>& vec, int node){

    if(vec[node] < 0)
        return node;

    // cout<<"oll correct"<<endl;
    return root(vec, vec[node]);
    
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

    cout<<rootA<<rootB<<rankA<<rankB<<endl;

    if(rankA > rankB){
        // 'b' will become child of 'a',
        vec[rootB] = rootA;         // make b's root parent as that of 'a'
        vec[rootA] += vec[rootB];   // updating total element in a
    }
    
    else{
        vec[rootA] = rootB;         // make a's root parent as that of 'b'
        vec[rootB] += vec[rootA];   // updating total element in b
    }

    cout<<"Done"<<endl;

}


int main(){

    vector<int> v(4,-1);

    cout<<root(v,4)<<root(v,3)<<endl;
    // print(v);

    // for(int i=0; i<5;++i){
    //     cout<<root(v,i)<<endl;
    // }

    UnionByRank(v,4,3);
        print(v);

    UnionByRank(v,2,4);
        print(v);

    UnionByRank(v,2,3);

    print(v);


    for(int i=0; i<5;++i){
        cout<<root(v,i)<<endl;
    }



}