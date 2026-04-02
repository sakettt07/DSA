#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// 3D Dp Ohhhhh yeaaahhh
int dp[501][501][3];
int helper(vector<vector<int>>&coins,int i,int j,int power){
    int n=coins.size();
    int m=coins[0].size();
    if(i>=n|| j>=m) return -1e9;
    if(i==n-1 &&j==m-1){
        if(power>0&&coins[i][j]<0)return 0;
        return coins[i][j];
    }
    // base condition
    if(dp[i][j][power]!=-1e9){
        return dp[i][j][power];
    }
    // starts moving right
    int right=coins[i][j]+helper(coins,i,j+1,power);
    // starts moving right but -ve val encountered
    int negRight=-1e9;
    if(coins[i][j]<0 &&power>0){
        negRight=helper(coins,i,j+1,power-1);
    }
    // starts moving down
        int down=coins[i][j]+helper(coins,i+1,j,power);
    // starts moving down but -ve val encountered
    int negDown=-1e9;
    if(coins[i][j]<0 &&power>0){
        negDown=helper(coins,i+1,j,power-1);
    }
    return dp[i][j][power]=max(max(right,negRight),max(down,negDown));
}
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++)
                    dp[i][j][k]=-1e9;
            }
        }
        return helper(coins,0,0,2);
    }
};
int main(){
    Solution s1;
    vector<vector<int>>coins={{0,1,-2},{-3,4,5},{-1,-2,0}};
    cout<<s1.maximumAmount(coins)<<endl;
return 0;
}