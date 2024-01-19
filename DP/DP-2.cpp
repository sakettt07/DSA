// Its my dp day-2 here i have solved minimum cost to climb the stairs.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// int solve(vector<int>&cost,int n){
//     // base casee
//     if(n==0)return cost[0];
//     if(n==1)return cost[1];
//     int ans= cost[n]+ min(solve(cost,n-1),solve(cost,n-2));
//         return ans;
// }
int solve2(vector<int>&cost,int n,vector<int> &dp){
    // base casee
    if(n==0)return cost[0];
    if(n==1)return cost[1];

    // step-3
    if(dp[n]!=-1){
                return dp[n];
        }

    dp[n]= cost[n]+ min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        return dp[n];
}
// this is the bottom up approach for the problem
int solve3(vector<int> &cost,int n){
    vector<int>dp(n+1);
    dp[0]=cost[0];
    dp[1]=cost[1];
    // 3rd step from the loop is running
    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);

    }
    return min(dp[n-1],dp[n-2]);
}
    int minCostClimbingStairs(vector<int>& cost) {
        // int n=cost.size();
        // int ans= min(solve(cost,n-1),solve(cost,n-2));
        // return ans;
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int ans= min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        return ans;

    }

};
int main(){

return 0;
}