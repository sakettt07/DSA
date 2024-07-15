// Two Graphs most famous questions Number of provinces and Course Scheduler.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// using normal DFS and a count variable
void DFS(int u,vector<bool>&visited,unordered_map<int ,vector<int>>&adj){
    visited[u]=true;
    for(int &v:adj[u]){
        if(!visited[v]){
            DFS(v,visited,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<bool>visited(n,false);
        int count=0;
        // making the adjacency list.
        unordered_map<int ,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }

        // calling the dfs function.
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS(i,visited,adj);
            count++;
            }
        }
        return count;
    }
};
int main(){

return 0;
}