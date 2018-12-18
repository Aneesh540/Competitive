#include<iostream>
#include<vector>
using namespace std;


template <class R, class T>
void Union(vector<R>& v, T a, T b){
    // while performing union all walo ko second ko change karo first me 

    auto new_set_value = v[a];      // ye wali value sab ko mil jayegi
    auto to_change = v[b];         // it's value to be changed to v[a]

    for(auto i=0; i<v.size(); ++i){
        
        if (v[i] == to_change){
            v[i] = new_set_value;
        }
    }


    
}


template <class R, class T>
bool Find(const vector<R>& v, T a, T b){

    if (v[a] == v[b]){
        cout<<"true"<<endl;
    }    
    

    else{
        cout<< "false"<<endl;
    }

}


int main(){

    vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };

    Union(v,4,3);
    Union(v,7,4);
    Union(v,3,5);
    Union(v,5,9);

    Find(v,7,3);
    Find(v,5,7);
    Find(v,9,4);
    
}