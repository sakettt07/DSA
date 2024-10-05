// Famous graph google question
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
typedef long long LL;
void DFS(int indx,unordered_set<int> &visited,unordered_map<int,vector<int>> &adj){
    // insert the intital to the visited
    visited.insert(indx);
    // now uske neighbours me ake dhundh lenge ki konse detonate honge
    for(int &it:adj[indx]){
        if(visited.find(it)==visited.end()){
            DFS(it,visited,adj);
        }
    }
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        // making the adjacency list for the bombs
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(i == j) //same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                //ditance dekhlo dono bombs k beech
                
                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }
                
            }
        }
        
        
        int result = 0;
        unordered_set<int> visited;
        
        for(int i = 0; i<n; i++) {
            DFS(i, visited, adj);
            int count = visited.size();
            result = max(result, count);
            visited.clear();
        }
        
        return result;
    }
};
int main(){

return 0;
}