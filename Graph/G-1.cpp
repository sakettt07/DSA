// Starting off with the new data structues which is graph
// A graph is a combination of nodes and edges
// Graphs are of two types directed and un directed -->In directed graph the direct of each node is defined and in undirected direction is not defined it can move in any directed it is connected to.
// Node-An entity to store the data
// Edges-Connecting the nodes.

// To represent a graph we have two techniques
// 1--->Adjacency Matrix
// 2--->Adjacency List
#include<bits/stdc++.h>
using namespace std;
// template<typename T>
// we can make the generic datatype for the node values


class graph{
    public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u,int v,bool direction){
        // direction=0->undirected
        // direction=1->directed

        // create an edge from u to v
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j :i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    // using adjacency matrix
    int numVertices=4;
    vector<vector<int>> adjacencyMatrix(numVertices,vector<int>(numVertices,0));
    // this is for directed graph
    adjacencyMatrix[0][1]=1;
    adjacencyMatrix[1][2]=1;
    adjacencyMatrix[2][3]=1;
    adjacencyMatrix[3][0]=1;
    // print the adjacency matrix
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            cout<<adjacencyMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
// using adjacency list
    int n;
    cout<<"Enter the number of nodes "<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        // Creating an undirected graph
        g.addEdge(u,v,0);
    }
    g.printAdj();
    

return 0;
}