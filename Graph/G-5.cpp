// in this we are going to perform the cycle detection for the directed graph using DFS
// the logic is almost the same but we are having an extra visited mapp because of the backtracking.
#include <bits/stdc++.h>
bool checkCycle(int node,unordered_map<int,bool>&visited,
unordered_map<int,bool>&dfsVisited,unordered_map<int,list<int>>& adj ){
  visited[node] = true;
  dfsVisited[node] = true;
  for(auto neighbour:adj[node]){
    if(!visited[neighbour]){
      bool cyclePresent = checkCycle(neighbour, visited, dfsVisited, adj);
      if(cyclePresent){
           return true;
      }
    } else if (dfsVisited[neighbour] == true) {
      return true;
    }
  }
  dfsVisited[node] = false;
  return false;
}
int detectCycleInDirectedGraph(int n, 
    vector < pair < int, int >> & edges) {
  // Write your code here.
   unordered_map<int,list<int>> adj;
   for (int i = 0; i < edges.size(); i++) {
     int u = edges[i].first;
     int v = edges[i].second;
     adj[u].push_back(v);
   }
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;
    for(int i = 0; i<n; i++){
      if(!visited[i]){
        bool cycle = checkCycle(i,visited,dfsVisited,adj);
        if(cycle){
          return true;
        }
      }
    }
   return false;
}