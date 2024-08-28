
// Imp dijkstra question for practice
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Solving with the classic dijkstra algorithm code(exact same but slight change is multiplication).
        // making the adjacency list
        unordered_map<int,vector<pair<int,double>>>adj;
        vector<double>result(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            // probabiity nikal lo us node ki
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        result[start]=1;
        // making the max heap to get the max probability
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        while(!pq.empty()){
            int curNode=pq.top().second;
            double curProb=pq.top().first;

            // upar wali node ko pop kardo info nikalne k bad
            pq.pop();
            for(auto &v :adj[curNode]){
                double adjProb=v.second;
                int adjNode=v.first;
                if(result[adjNode]<curProb*adjProb){
                    result[adjNode]=curProb*adjProb;
                    pq.push({result[adjNode],adjNode});
                }
            }

        }
        return result[end];
    }
};
int main(){

return 0;
}