// LeetCode -2218

// In this problem we are  given a 2D array of piles and coins in it we have to choose the maximum amount from the single pile as
// we can choose the coins from the pile in any order only k coins.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int dp[1001][2001];
int solve(int indx,vector<vector<int>>& piles,int k){
    if(indx>=piles.size())return 0;

    if(dp[indx][k]!=-1){
        return dp[indx][k];
    }
    int notTaken=solve(indx+1,piles,k);

    int taken=0;
    int sum=0;
    // traversing the chosen pile for their coins
    for(int j=0;j<min((int)piles[indx].size(),k);j++){
        sum+=piles[indx][j];
        taken=max(taken,sum+solve(indx+1,piles,k-(j+1)));
    }
    return dp[indx][k]=max(notTaken,taken);
}

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,piles,k);
        
    }
};
int main(){

    // main function which controllss the whole program

    cout<<"The DP Problem"<<endl;
    Solution s;
    vector<vector<int>>piles={{1,100,3},{7,8,9}};

    cout<<s.maxValueOfCoins(piles,2);

    


return 0;
}