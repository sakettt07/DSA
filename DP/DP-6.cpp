#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Writing the recursive approach for the problem It will results in the TLE.

// Memoizing the code to avoid TLE
int n;
int dp[2501][2501];
int solve(int indx,int prev,vector<int>& nums){
    // base case
    if(indx>=n)return 0;  //condition for the out of bound

    // Memoizing base case
    if(prev!=-1&&dp[indx][prev]!=-1)return dp[indx][prev];
    // case-1 if we are taking the element
    int take=0;  //initializing it with 0

    // The below statement in the for loop executes when the prev value is strictly smaller then the current value
    if(prev==-1||nums[prev]<nums[indx]){
        take=1+solve(indx+1,indx,nums);
    }
    // Case-2 When we are skipping the current element
    int skip=solve(indx+1,prev,nums);
    // returning the maximum of both the cases

    // this extra condition s for checking the initial index of the prev which can't be negative.
    if(prev!=-1){
        dp[indx][prev]= max(skip,take);
    }
    return max(skip,take);
}
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();

        // the below condition is used for filling the array with the -1
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
        
    }
};


// solution for the maximum length pair chain

class Solution {
public:
int n;
int dp[2501][2501];
int solve(int indx,int prev,vector<vector<int>>& pairs){
    // base case
    if(indx>=n)return 0;  //condition for the out of bound

    // Memoizing base case
    if(prev!=-1&&dp[indx][prev]!=-1)return dp[indx][prev];
    // case-1 if we are taking the element
    int take=0;  //initializing it with 0

    // The below statement in the for loop executes when the prev value is strictly smaller then the current value

    // here we are  comparing the previous pair's 1st index element with next pair's 0th index element.
    if(prev==-1||pairs[prev][1]<pairs[indx][0]){
        take=1+solve(indx+1,indx,pairs);
    }
    // Case-2 When we are skipping the current element
    int skip=solve(indx+1,prev,pairs);
    // returning the maximum of both the cases

    // this extra condition s for checking the initial index of the prev which can't be negative.
    if(prev!=-1){
        dp[indx][prev]= max(skip,take);
    }
    return max(skip,take);
}
// similar code as of LIS only a slight change
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        n=pairs.size();
        // sorting the pairs as it is given the You can select pairs in any order.
        sort(begin(pairs),end(pairs));
        // the below condition is used for filling the array with the -1
        return solve(0,-1,pairs);
    }
};
int main(){

return 0;
}