#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int FOO = 1;
const int MAX = 1000001;
vector<int> adjList[MAX];

vector<int> in_degree(MAX,0);
vector<bool> visited(MAX,false);
queue<int> output_queue;

void input_graph(int nodes, int edges){
    in_degree[0] = -1;

    for(int i=0; i<edges; ++i){
        int x,y;
        cin>>x>>y;

        adjList[x].push_back(y);
        in_degree[y] += 1;
    }
}


void print(int nodes){

    for(int i=1; i<=nodes; ++i){
        cout<<in_degree[i]<<", ";
    }
    
    cout<<endl;
}


void khan_algorithm(int nodes){
        bool flag = false;


        for(int i=1; i<=nodes; ++i){
            cout<<"running for = "<<i;

            if(in_degree[i] == 0 && visited[i] == false){
                
                cout<<" 0 degree node "<<i<<endl;

                flag = true;

                visited[i] = true;
                output_queue.push(i);

                for(int j=0; j < adjList[i].size(); ++j){

                    int adjNode = adjList[i][j];
                    in_degree[adjNode] -= 1; 
                    }

                    print(nodes);  
            
                }

            

            else{
                cout<<"||| NOT INVOLVED"<<endl;
            }

        }

        if(flag == true){
            cout<<"RUNNING FOR STACK = "<<FOO<<endl;
            FOO += 1;
            khan_algorithm(nodes);
        }


    



    
}

int main(){

    int nodes,edges;
    cin>>nodes>>edges;

    input_graph(nodes,edges);
    khan_algorithm(nodes);
    print(nodes);

    
    cout<<output_queue.size()<<endl;
    while(!output_queue.empty()){
        cout<<output_queue.front()<<" ";
        output_queue.pop();
    }cout<<endl;


}

