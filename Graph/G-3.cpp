// Performing the DFS traversal technique 
// This tracversal technique is almost similar to BFS but the  only difference is that it checks in the depth of the node
// Whereas the BFS checks in the same level of that node.
#include<bits/stdc++.h>
using namespace std;


void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &component){
    component.push_back(node);
    visited[node]=true;

    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,component);
        }
    }

}
vector<vector<int>>depthFirstSearch(int v,int E,vector<vector<int>> &edges){

    // again prepared the adjacency list for the node and its neighbours.
    unordered_map<int,list<int>>adj;
     for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>ans;

    // the below will manages that the node is visited or not.
    unordered_map<int,bool>visited;
    for(int i=0;i<v;i++){
        if (!visited[i])
        {
            vector<int>component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
}
int main(){

return 0;
}