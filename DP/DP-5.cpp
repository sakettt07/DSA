// maximum-alternating-subsequence-sum leetcode
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
typedef long long ll;  //this will converting the code to the long long type 
int n;
// the statement below written is memoizing the code
long long dp[1000001][2];
// resurion method give the TLE
ll solve(int indx,vector<int>& nums,bool flag){
    if(indx>=n)return 0;


    if(dp[indx][flag]!=-1)return dp[indx][flag];
    // writing the two cases
    // Case-1 :skip case
    ll skip=solve(indx+1,nums,flag);
    ll val=nums[indx];
    if(flag==false){
        val=-val;
    }
    // Case-2 take case
    ll take=solve(indx+1,nums,!flag)+val;
    return dp[indx][flag]=max(skip,take);
}
    long long maxAlternatingSum(vector<int>& nums) {
      n=nums.size();
      memset(dp,-1,sizeof(dp));
      return solve(0,nums,true);  
    }
};
int main(){

return 0;
}