#include <iostream>
#include <vector>
#include <queue>
#define vi vector<int>
using namespace std;


void input_graph(vector<vi >& v, int nodes, int edges){

    for(int i=0;i<edges;++i){
         int x,y;cin>>x>>y;
         v[x].push_back(y);
         v[y].push_back(x);
     }
}


void adj_list(vector<vi >& v){
    int nodes = v.size();

    for(int i=1; i<nodes; ++i){

        cout<<i<<": ";
        
        for(int j = 0; j < v[i].size(); ++j)
         {
             cout << v[i][j] << "-> ";
         }
         cout << endl;

    }
}

int connected(const vector <vi >& v, int starting_node, vi discovered, int reachable_node){
    // for each discovered node increase count of reachable
   


    
}



int main(){
    int edges,nodes;
    cin>>nodes>>edges;

    vector< vi > v(nodes + 1, vector<int>());
    input_graph(v,nodes,edges);

    // adj_list(v);

    int foo;
    cin>>foo;

    cout<<connected(v,foo)<<endl;



}
