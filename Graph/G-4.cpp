// Cycle detection in undirected graph using BFS ,DFS.
#include<bits/stdc++.h>
using namespace std;
bool isCycleBFS(int src,unordered_map<int,bool>&visited,unordered_map<int,list<int>> &adj){
    unordered_map<int,int>parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int>qu;
    qu.push(src);
    while(!qu.empty()){
        int frontnode=qu.front();
        qu.pop();
        for(auto i:adj[frontnode]){
            if(visited[i]=true && i!=parent[frontnode]){
                return true;
            }
            else if(!visited[i]){
                qu.push(i);
                visited[i]=1;
                parent[i]=frontnode;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    // creating the adjacency list for the BFS traversal.
    unordered_map<int,list<int>>adj;
     for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // to handle the disconnected components
    unordered_map<int,bool>visited;

     for(int i=0;i<n;i++){
        if (!visited[i])
        {
            bool ans=isCycleBFS(i,visited,adj);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}


int main(){

return 0;
}