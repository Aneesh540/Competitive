#include<iostream>
#include<vector>
#include<queue>
#define PI pair<int,int>
using namespace std;

const int MAX = 1000001;
vector<pair<int,int> > adjList[MAX];
vector<int> dist(MAX,MAX);
vector<bool> visited(MAX,false);


inline bool relaxation(int u, int v, int weight){

    int newValue = dist[u] + weight;

    cout<<"inside relax --> "<<newValue<<dist[v];
    if(newValue < dist[v]){
        dist[v] = newValue;
        return true;
    }

    else{
        return false;
    }

}



void dijkstra(int startNode){

    dist[startNode] = 0;
    priority_queue<PI, vector< PI >, greater< PI > > pq;

    pq.push({startNode,0});

    while(!pq.empty()){


        // extract the minimum value node from pri. queue
        PI p = pq.top(); pq.pop();
        int weight = p.first;
        int node = p.second;

        // mark the node as visited if not visited previously
        // iterate over it's adjacency list and 
        // cout<<"**** "<<node<<visited[node]<<endl;
        if(visited[node] == false){
            cout<<"executed for node "<<node<<endl;
            // node is said to be visited if all it's adjacent node is explored

            visited[node] = true;
            // cout<<adjList[node].size()<<" %%%%%%%%%%%%%%%"<<endl;
            for(int i=0; i<adjList[node].size(); ++i){
                cout<<"i = "<<i<<"&&&&&&&&&&&&&&&&&&"<<endl;
                int weight = adjList[node][i].first;
                int node_v = adjList[node][i].second;

                if(relaxation(node,node_v,weight) == true){
                    cout<<"relaxation done for node adj = "<<node_v<<endl;
                    pq.push({dist[node_v], node_v});
                }
            }
        }

        

    }

}



int main(void){

    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; ++m){
        int a,b,w;
        cin>>a>>b>>w;

        adjList[a].push_back({w,b});
    }

    for(int i=0;i<n+1; ++n){
        cout<<adjList[i].size()<<endl;
    }cout<<"OVER ______________________________"<<endl;

    cout<<visited[45]<<endl;

    dijkstra(1);

    for(int i=0; i<n; ++i){
        cout<<i<<" -> "<<dist[i]<<endl;

    }
    
}