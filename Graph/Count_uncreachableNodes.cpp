#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void DFS(int i,unordered_map<int,vector<int>>&adj,vector<bool>&visitedd,long long int &size){
    visitedd[i]=true;
    size++;
    for(int &v:adj[i]){
        if(!visitedd[v]){
            DFS(v,adj,visitedd,size);
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        // Solving using normal DFS traversal
        unordered_map<int,vector<int>>adj;
        for(auto& vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        } 
        vector<bool>visitedd(n,false);

        long long int remainingValue=n;
        long long int result=0;

        for(int i=0;i<n;i++){
            if(!visitedd[i]){
                long long int size=0;
                DFS(i,adj,visitedd,size);
                result+=(size)*(remainingValue-size);
                remainingValue-=size;
            }
        }
        return result;
    }
};
int main(){
    Solution s1;
    vector<vector<int>>edges={{0,1},{2,3},{0,4}};
    cout<<s1.countPairs(5,edges);
return 0;
}