#include<iostream>
#include<vector>
#include<stack>
#include<utility>
#include<algorithm>
using namespace std;
const int MAX = 10000;

// THIS TOPOLOGICAL SORT WILL PRINT THE CONNECTED COMPONENT IN BULK
// SEE HACKEREARTH QUESTION OF topological sort for more
// to print the lexiographically smallest order there is a different approach

vector<bool> visited(MAX,false);
stack<int> mystack;
vector<int> adjList[MAX];

void topological_sort(int startNode){
    // point #1 ) if all neighbour of node is visted then push it into the stack
    // point #2 ) if not then
    // point #3 ) iterate through all it's neighbours and do step 1. for them

    if(visited[startNode] == false){ // point #2 
        
        // sort(adjList[startNode].begin(), adjList[startNode].end(),greater<int>());

        for(int i=0; i<adjList[startNode].size(); ++i){
            

            int this_node = adjList[startNode][i];

            // point # 3
            if(visited[this_node] == false){
                topological_sort(this_node);
           
           
            }
        }
    }



    // point #2 
    visited[startNode] = true;
    mystack.push(startNode);


    // the problem with this function is that it will work only for strongly connected components
    // to cover this up we have a another  driver fucntion (check below code)
    
}


void driver(int totalNodes){
    // CAUTION :: nodes starting from 1 

    for(int i=1; i<=totalNodes; ++i){
        

        if(visited[i] == false){
            cout<<"running for node = "<<i<<endl;
            topological_sort(i);

        }
    }
}


int main(){

    int n,m;
    cin>>n>>m;
    

    for(int i=0; i<m; ++i){
        int a,b,w;
        cin>>a>>b;



        adjList[a].push_back(b);  
    
    }

    cout<<adjList[1].size()<<endl;

    driver(n);

    while(!mystack.empty()){
        cout<<mystack.top()<<" ";
        mystack.pop();
    }
    cout<<endl;



}