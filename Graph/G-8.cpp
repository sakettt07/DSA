// Shortest Path algorithm in graphh.
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    // do bfs
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    queue<int>qu;
    qu.push(s);
    parent[s]=-1;
    visited[s]=true;
    while(!qu.empty()){
        int frontN=qu.front();
        qu.pop();

        for(auto i:adj[frontN]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=frontN;
                qu.push(i);
            }
        }
    
    }
    // till Now we have setted our parent map. 



    // now making the final path array 
    vector<int>ans;
    int currentN=t;
    ans.push_back(t);
    while(currentN!=s){
        currentN=parent[currentN];
        ans.push_back(currentN);
    }
    reverse(begin(ans),end(ans));
    return ans;
	
}

int main(){

return 0;
}