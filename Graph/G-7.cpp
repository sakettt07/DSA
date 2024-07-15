// Studying about Kahn's Algorithm. ()
#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // creating adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // indegree wala step perform karo
    vector<int>indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    // 0 walo ko queue m daalna h
    queue<int>qt;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            qt.push(i);
        }
    }

    // do BFS
    vector<int>ans;
    while(!qt.empty()){
        int front=qt.front();
        qt.pop();
        ans.push_back(front);

        for(auto it:adj[front]){
            indegree[it]--;
            if(indegree[it]==0){
                qt.push(it);
            }
        }
    }
    return ans;
}
int main(){

return 0;
}