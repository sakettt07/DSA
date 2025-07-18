// In this file we  have solved a DP problem to count all the possible routes.
// we are given with the locations , start end, and the fuel we have to travel with.
// we have to find the total number of routes we can take to reach the destination with the present amount of fuel.
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int n;
    const int MOD=1e9+7;
    int dp[101][201];
    int solve(int idx,int end,int fuel,vector<int>&locations){
        if(fuel<0)return 0;
        if(dp[idx][fuel]!=-1)return dp[idx][fuel];
        int ans=0;
        if(idx==end){
            ans+=1;
        }
        for(int j=0;j<n;j++){
            if(idx!=j){
                int remainingFuel=fuel-abs(locations[idx]-locations[j]);
                ans=(ans+solve(j,end,remainingFuel,locations))%MOD;
            }
        }
        return dp[idx][fuel]=ans;
    }
    int countRoutesUtil(int start, int end, int fuel, vector<int>& locations) {
        n=locations.size();
        memset(dp, -1, sizeof(dp));
        return solve(start, end, fuel, locations);
    }

};
int main(){

    Solution sol;
return 0;
}