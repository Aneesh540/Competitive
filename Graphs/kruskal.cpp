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
        // cout<<"("<<x.first<<", "<<x.second<<")  ";
        cout<<x<<", ";

    cout<<endl;
}


template<class T>
void print2(T anything){
    for(auto x: anything){
        cout<<"("<<x.first<<", "<<x.second.first<<",, "<<x.second.second<<") ";
    }cout<<endl;
}



// template<class T1, class T2>
bool sortbysec(const pair<int, float>& a, const pair<int, float>& b){
    return (a.second > b.second);
}

bool sortbythird(const threePair& a, const threePair& b){
    return (a.second.second < b.second.second);
}


int root(vector<int>& v, int node){

    if(v[node] < 0)
        return node;

    return root(v, v[node]);

}


void Union(vector<int>& v, int a, int b){

    int rootA = root(v,a);
    int rootB = root(v,b);

    int rankA = abs(v[rootA]);
    int rankB = abs(v[rootB]);

    if(rootA != rootB){

        if(rankA > rankB){
            // B will become child of A
            
            v[rootA] += v[rootB];
            v[rootB] = rootA;

        }

        else{
        
        v[rootB] += v[rootA];
        v[rootA] = rootB;
        }

    }

}






int Kruskal(vector< threePair >& vec){
    sort(vec.begin(),vec.end(),sortbythird);

    
    print2(vec);

    int totalNodes = vec.size();

    vector<int> array(totalNodes,-1);
    

    int MST = 0;

    for(auto i=0; i<totalNodes; ++i){

        int nodeWeight = vec[i].first;

        int nodeOne = vec[i].second.first;
        int nodeTwo = vec[i].second.second;

        cout<<nodeWeight<<" "<<nodeOne<<" "<<nodeTwo<<endl;

        if(root(array,nodeOne-1) != root(array,nodeTwo-1)){
            // if not forming cycle then add perfrom Union of the nodes and add its weight to MST 
            
            Union(array,nodeOne-1,nodeTwo-1);
            MST += nodeWeight;

            cout<<"added node "<<nodeOne<<" & "<<nodeTwo <<" MST = "<<MST<<endl;

        }
        

    }

    return MST;
}




int main(){

    // vector< pair<int,float> > vec;
    vector< threePair > vec;

    vec.push_back({1,{2,7}});
    vec.push_back(make_pair(1,make_pair(4,6)));
    vec.push_back(make_pair(4,make_pair(2,9)));
    vec.push_back(make_pair(4,make_pair(3,8)));
    vec.push_back(make_pair(2,make_pair(3,6)));



    
    cout<<Kruskal(vec)<<endl;// answer is 19



    

}