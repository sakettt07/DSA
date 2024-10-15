#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// using the DP appraoch
int n;
int solve(vector<int>& days, vector<int>& costs,int indx,int n,vector<int>&dp){
    if(indx>=n){
        return 0;
    }
    // memoization appraoch
    if(dp[indx]!=-1){
        return dp[indx];
    }
    // option 1 for the 1Day pass
    int option1=costs[0]+solve(days,costs,indx+1,n,dp);

    // option 2 when we can take a 7day pass which means we can attend any 7 days but consecutive.
    int i;
    for(i=indx;i<n&&days[i]<days[indx]+7;i++);
    int option2=costs[1]+solve(days,costs,i,n,dp);

    // option 3 when we are taking the 30Days Pass.
    for(i=indx;i<n&&days[i]<days[indx]+30;i++);
    int option3=costs[2]+solve(days,costs,i,n,dp);

    dp[indx]= min(option1,min(option2,option3));
    return dp[indx];
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        vector<int>dp(n+1,-1);
        return solve(days,costs,0,n,dp);
    }
};
int main(){

return 0;
}