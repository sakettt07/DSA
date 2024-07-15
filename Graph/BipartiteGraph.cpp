// Studied the concept of bipartite graph performing implementation.
#include<bits/stdc++.h>
using namespace std;

// below is the DFS approach for the problem.
class Solution {
    public:
bool bipartiteGraph(vector<int> adj[],int curr,vector<int>&colors,int currCol){
    colors[curr]=currCol;    //initial color kardiya humne
    
    // visiting the adjacent nodes
    for(int &v:adj[curr]){
        if(colors[v]==colors[curr])return false;
        
        // if we haven't colored
        if(colors[v]==-1){
            int colorOfV=1-currCol;
            if(bipartiteGraph(adj,v,colors,colorOfV)==false){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int>adj[]){
	    // no need to create a adjacency list its already given so diretly using it only
	    vector<int>colors(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(colors[i]==-1){
	            if(bipartiteGraph(adj,i,colors,1)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};


class Solutoion{
    public:
    bool bipartiteGraphBfs(vector<int>adj[],int node,vector<int> &colors,int currColor){
        queue<int>qu;
        qu.push(node);
        colors[node]=currColor;

        while(!qu.empty()){
            int u=qu.front();
            qu.pop();

            for(int &v:adj[u]){
                if(colors[v]==colors[currColor])return false;

                else if(colors[v]==-1){
                    colors[v]=1-colors[u];
                    qu.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj){
        int n=adj.size();

        vector<int>colors(n,-1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(bipartiteGraphBfs(adj,i,colors,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){

return 0;
}