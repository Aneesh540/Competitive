#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define threeSome pair<int, pair<int,int> >
#define vp pair<int,int>

using namespace std;




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


int prims(vector< vector<pair<int, int> > >& adjList, int startNode,vector<bool>& visited ){

    priority_queue< vp, vector<vp> , greater<vp> > pq;
    // declaring a priority queue

    pq.push({0,startNode});               // 0 is initial weight of startNode
    int MST = 0;

    while(!pq.empty()){
        
        pair<int,int> p = pq.top(); pq.pop();

        int weight = p.first;
        int node = p.second;

        
        // traverse it's adjacency list
        

            if(visited[node] == false){

                visited[node] = true;
                MST += weight;
                // if node is not already visited then push its neighbourhood 
                // into the priority queue
                
                for(int i=0; i<adjList[node].size(); ++i){

                    int neighbourNode = adjList[node][i].second;
                    // cout<<"neighbour of "<<node<<" == "<<neighbourNode<<endl;

                    if(visited[neighbourNode] == false){
                        pq.push(adjList[node][i]);}


                }
            }
        

}

        return MST;

}

int main(){

    // priority_queue<threeSome,vector<threeSome> , greater<threeSome> > pq;

    // pq.push({14,{3,1}});
    // pq.push({2,{5,2}});
    // pq.push({28,{7,9}});
    // pq.push({1,{1,4}});

    // threeSome x = pq.top();
    // cout<<x.first<<x.second.first<<x.second.second<<endl;
    // pq.pop();

    // x = pq.top();
    // cout<<x.first<<x.second.first<<x.second.second<<endl;
    // pq.pop();



    // x = pq.top();
    // cout<<x.first<<x.second.first<<x.second.second<<endl;
    // pq.pop();

    int nodes;
    int edges;

    cin>>nodes>>edges;
    

    vector< vector<pair<int, int> > > adjList(nodes, vector< pair<int, int> >());
    vector<bool> visited(nodes,false);
    

    for(int i=0; i<edges; ++i){
        int x,y,w;
        cin>>x>>y>>w;
        cout<<" -- "<<x<<y<<w<<endl;

        adjList[x-1].push_back({w,y-1});
        adjList[y-1].push_back({w,x-1});
    }

    cout<<prims(adjList,1,visited);

}