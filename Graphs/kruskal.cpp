#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define threePair pair<int, pair<int,int> > 
// #define T2 pair<int, float> 
using namespace std;

template<class T>
void print(T anything){
// for printing anything, pythonista

    for(auto x: anything)
        cout<<"("<<x.first<<", "<<x.second<<")  ";

    cout<<endl;
}



// template<class T1, class T2>
bool sortbysec(const pair<int, float>& a, const pair<int, float>& b){
    return (a.second > b.second);
}

bool sortbythird(const threePair& a, const threePair& b){
    return (a.second.second < b.second.second);
}



int main(){

    // vector< pair<int,float> > vec;
    vector< threePair > vec;

    vec.push_back(make_pair(1,make_pair(2,7)));
    vec.push_back(make_pair(1,make_pair(4,6)));
    vec.push_back(make_pair(4,make_pair(2,9)));
    vec.push_back(make_pair(4,make_pair(3,8)));
    vec.push_back(make_pair(2,make_pair(3,6)));


    // vec.push_back(make_pair(15,8.4));
    // vec.push_back(make_pair(11,3.5));
    // vec.push_back(make_pair(1,3.5));
    // vec.push_back(make_pair(3,12.5));
    // vec.push_back(make_pair(5,3.5));

    // print(vec);

    sort(vec.begin(),vec.end(),sortbythird);
    // print(vec);

    
    

}