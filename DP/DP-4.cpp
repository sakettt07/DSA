// coin change-2 question
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// DP standard Problem

// Trying the recursion approach first (This will cause runtime error)
int n;
// now adding the memoization code into the same.
int dp[301][5001];
int solve(int i,int amt,vector<int>& coins){
    if(amt==0) return 1;
    if(i==n) return 0;
    if(dp[i][amt]!=-1)return dp[i][amt];
    if(amt<coins[i]){
        return dp[i][amt]=solve(i+1,amt,coins);
    }
    int take=solve(i,amt-coins[i],coins);
    int skip=solve(i+1,amt,coins);
    return dp[i][amt]= take+skip;

}
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,amount,coins);
    }
};

// coin change -1
class Solution {
public:
// Trying up with the recursion approach
// as the recursion approach results in the TLE so memoizing it.
int dp[10010];
int solve(int amt,vector<int>& coins){
    if(amt==0)return 0;
    if(dp[amt]!=-1)return dp[amt];
    
    int ans=INT_MAX;
    for(int coin:coins){
        if(amt-coin>=0)
        ans=min(ans+0LL,solve(amt-coin,coins)+1LL);
        // in the above statement LL is added to avoid the overflow.
    }
    return dp[amt]=ans;
}
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int anss=solve(amount,coins);
        return anss==INT_MAX ? -1 :anss;
    }
};
int main(){

return 0;
}