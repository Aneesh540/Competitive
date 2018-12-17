#include <iostream>
#include <vector>
#include <stack>
#define vi vector<int>
using namespace std;

template <class T>
void print(T& v){
    
    cout<<endl;
    for(auto it = v.begin(); it!= v.end(); ++it){
        cout<<*it<<", ";
    }
    cout<<endl;
}

void input_directed_graph(vector< vi >& v, int nodes, int edges){

    for(int i=0; i<edges; ++i){
        int x,y;
        cin>>x>>y;

        v[x].push_back(y);
    }

}


void print_adj_list(const vector< vi >& v){

    for(auto i=1; i < v.size(); ++i){
        // bahar wali line  k liye loop
         cout<<i<<" :: ";
         for(auto it=v[i].begin(); it != v[i].end(); ++it)
         {
             cout << *it << "-> ";
         }
         cout << endl;

    }
}


void dfs_iterative(const vector< vi >& v, int starting_node){
    int nodes = v.size();
    vi visited(nodes+1,-1);        // visited = -1 then not visited if +1 then visited
    
    stack<int> stack;

    //push starting node into stack and mark visited = 1
    stack.push(starting_node);
    visited[starting_node] = 1;
    

    while(!stack.empty()){

        int vertex =  stack.top();
        stack.pop();
        cout<<vertex<<", ";

        for(auto j = 0; j<v[vertex].size(); ++j){ // for every adjacent vertex of this vertex,
                                                  // push its adj. vertex into stack if not discovered

            int current_node = v[vertex][j];



            if (visited[current_node] == -1){      // if not discovered then push it into stack
                visited[current_node] = 1;
                stack.push(current_node);
            }
        }


    }

}

void dfs_recursive(const vector< vi >&v , int starting_node, vi& discovered){
    int nodes = v.size();

    discovered[starting_node] = 1;

    cout<<starting_node<<", ";

    for(auto j =0; j< v[starting_node].size(); ++j){

        int this_node = v[starting_node][j];

        if(discovered[this_node] == -1)
            dfs_recursive(v,this_node,discovered);
    }
    

}


int main(){

    int nodes;
    cin>>nodes;

    int edges;
    cin>>edges;

    vi discovered(nodes,-1);
    
    print(discovered);

    vector< vi > v(nodes + 1, vector<int>());           // Graph initialisation
    input_directed_graph(v,nodes,edges);
    print_adj_list(v);
    dfs_iterative(v,1);
    dfs_recursive(v,1,discovered);

    print(discovered);
}