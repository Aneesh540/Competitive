#include<bits/stdc++.h>
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

void input_graph_undirected(vector<vi >& v, int nodes, int edges){
    // graph starting from 1, write edges 
    cout<<"Write edges "<<endl;

    for(int i=0;i<edges;++i){
         int x,y;cin>>x>>y;

         v[y].push_back(x);
         v[x].push_back(y);
     }
}


void adj_list(vector<vi >&v, int nodes){

    for(int i=1; i<nodes+1; ++i){

        cout<<i<<": ";
        
        for(int j = 0; j < v[i].size(); ++j)
         {
             cout << v[i][j] << "-> ";
         }
         cout << endl;

    }
}


void reach(vector< vi >& v, vi levels, int start){

    vector<int> levels(nodes+1,-1);
    // list of all visited nodes (nodes + 1) for better understanding

    queue<int> queue;
    queue.push(start);      // pushing the first element in queue
    levels[start] = 0;     // mark start node as visited

    while(!queue.empty()){

        // pop element
        int element = queue.front();
        queue.pop();

        // print element
        cout<<element<<", ";

        // going through adjacency list of element  
        for(int i=0; i<v[element].size(); ++i){

            int p = v[element][i];

            if(levels[p] == -1){

                // cout<<" pushed "<<v[element][i]<<endl;

                queue.push(v[element][i]);
                levels[p] = levels[element] + 1;    // it's level is parent level + 1
                                                    // and parent is "element"
            }
        }


    }

    print(levels);


}



void bfs(vector<vi >&v, int nodes, int start){

    vector<int> visited(nodes+1,-1);
    // list of all visited nodes (nodes + 1) for better understanding

    queue<int> queue;
    queue.push(start);      // pushing the first element in queue
    visited[start] = 1;     // mark start node as visited

    while(!queue.empty()){

        // pop element
        int element = queue.front();
        queue.pop();

        // print element
        cout<<element<<", ";


        for(int i=0; i<v[element].size(); ++i){

            int p = v[element][i];

            if(visited[p] == -1){

                // cout<<" pushed "<<v[element][i]<<endl;

                queue.push(v[element][i]);
                visited[p] = 1;
            }
        }


    }


}

int main(){
    // given a adjacency list representation

    int nodes;
    int edges;

    cin>>nodes;
    edges = nodes - 1;

    vector< vi > v(nodes+1, vector<int>());

    input_graph_undirected(v,6,6);
    adj_list(v,6);

    bfs(v,6,1);

    reach(v,6,1);

    
}