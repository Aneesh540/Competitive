#include <iostream>
#include <vector>
#include<stack>
#define vi vector<int>
using namespace std;

//     4    // nodes
//     5   //edges
//     1 2 //showing edge from node 1 to node 2
//     2 4 //showing edge from node 2 to node 4
//     3 1 //showing edge from node 3 to node 1
//     3 4 //showing edge from node 3 to node 4
//     4 2 //showing edge from node 4 to node 2

void input_graph(vector<vi >& v, int nodes, int edges){

    for(int i=0;i<edges;++i){
         int x,y;cin>>x>>y;
         v[x].push_back(y);
     }
}

void adj_list(vector< vector<int> >&v, int nodes){

    for(int i=1; i<nodes+1; ++i){

        cout<<i<<": ";
        
        for(int j = 0; j < v[i].size(); ++j)
         {
             cout << v[i][j] << "-> ";
         }
         cout << endl;

    }
}


    
int main(){
    int nodes ;
    int edges ;

    cin>>nodes;
    vector< vi > v(nodes+1, vector<int>());     // nodes+1 bcoz nodes starting with 1 for better interpretation

    cin>>edges;

    input_graph(v,nodes,edges);
    adj_list(v,nodes);
     




}