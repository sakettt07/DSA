// Its a prim's algorithm question where we have to find the minimum cost after connecting all the points together we can us the same exact code as of prims algorithm with a slight change in the making of the adjacency list.
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
class Solution {
public:
// using the exact same code of the prims algorithm.
int prims(vector<vector<P>> &adj,int V){
    priority_queue<P,vector<P>,greater<P>>pq;
    pq.push({0,0});
    vector<bool>InMst(V,false);
    int sum=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int node=p.second;
        int wt=p.first;
        
        if(InMst[node]==true){
            continue;
        }
        InMst[node]=true;
        sum+=wt;

        for(auto &v:adj[node]){
            int neighbor=v.first;
            int neighborWt=v.second;
            if(InMst[neighbor]==false){
                pq.push({neighborWt,neighbor});
            }
        }
    }
    return sum;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        // creating the adjacency list.

        int V=points.size();
        vector<vector<P>>adj(V);
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){

                // calculating the distance first then push
                // all coordinates.
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];
                // the manhattan distance
                int dist=abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});

            }
        }
        return prims(adj,V);
    }
};
int main(){

return 0;
}