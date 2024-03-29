// we will be doing house robber in the with the help of recursion and dp technique.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// 1st approach- The recursion method pof this gives the TLE
int solve(vector<int>& nums,int i,int n){
    if(i>=n)return 0;
    int steal=nums[i]+solve(nums,i+2,n);
    int skip=solve(nums,i+1,n);
    return max(steal,skip);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,n);
        
    }
// 2nd recursion+memoization
int dp[101];
int solve(vector<int>& nums,int i,int n){
    if(i>=n)return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int steal=nums[i]+solve(nums,i+2,n);
    int skip=solve(nums,i+1,n);
    return dp[i]= max(steal,skip);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,n);
        
    }
    // bottom up approach or tabulation method
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+dp[i-2];
            int skip=dp[i-1];
            dp[i]=max(steal,skip);
        }
        return dp[n];
        
    }

};

// house robber 2
class Solution {
public:
int dp[101];
int solve(vector<int>& nums,int i,int n){
    if(i>n)return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int steal=nums[i]+solve(nums,i+2,n);
    int skip=solve(nums,i+1,n);
    return dp[i]= max(steal,skip);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        memset(dp,-1,sizeof(dp));

        // taking up the first case in which we will be taking the 0th house.
        int take_house=solve(nums,0,n-2);
        memset(dp,-1,sizeof(dp));
        int not_take=solve(nums,1,n-1);
        return max(take_house,not_take);
    }
};
int main(){

return 0;
}