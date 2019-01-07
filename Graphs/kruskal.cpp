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


// int root(vector<int>& v, int node){

//     if(v[node] < 0)
//         return node;

//     return root(v, v[node]);

// }


// void Union(vector<int>& v, int a, int b){

//     int rootA = root(v,a);
//     int rootB = root(v,b);

//     int rankA = abs(v[rootA]);
//     int rankB = abs(v[rootB]);

//     if(rootA != rootB){

//         if(rankA > rankB){
//             // B will become child of A
            
//             v[rootA] += v[rootB];
//             v[rootB] = rootA;

//         }

//         else{
        
//         v[rootB] += v[rootA];
//         v[rootA] = rootB;
//         }

//     }

// }



int root(vector<int>& vec, int node){

    if(vec[node] < 0)
        return node;


    int rootOfNode = root(vec, vec[node]);
    vec[node] = rootOfNode;

    return rootOfNode;
    
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


    cout<<" Union done "<<endl;


}




int main(){

    // vector< pair<int,float> > vec;
    vector< threePair > vec;

    vec.push_back({1,{2,7}});
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
    print2(vec);

    int totalNodes = vec.size();

    vector<int> array(totalNodes,-1);
    

    int MST = 0;

    for(int i=0; i<totalNodes; ++i){

        int nodeOne = vec[i].first;

        int nodeTwo = vec[i].second.first;
        int nodeWeight = vec[i].second.second;

        cout<<nodeWeight<<" "<<nodeOne<<" "<<nodeTwo<<endl;

        if(root(array,nodeOne-1) != root(array,nodeTwo-1)){
            // if not forming cycle then add perfrom Union of the nodes and add its weight to MST 
            
            UnionByRank(array,nodeOne-1,nodeTwo-1);
            MST += nodeWeight;

            cout<<"added node "<<nodeOne<<" & "<<nodeTwo <<" MST = "<<MST<<endl;

        }

   

        

        

    }



    cout<<MST<<endl;
    

}