//DP-HARD\ReducingDishes.cpp  -------------------  1402--------------

// Problem Description: 
// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
// Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.
// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int n;
int dp[501][501];
//Brute force methodd.(Using Recursion+ Memoization method).
int solve(int indx,int time,vector<int>&satisfaction){
    if(indx>=n)return 0;

    if(dp[indx][time]!=-1){
        return dp[indx][time];
    }

    int cook=time*satisfaction[indx]+solve(indx+1,time+1,satisfaction);
    int notCook=solve(indx+1,time,satisfaction);

    return dp[indx][time]= max(cook,notCook);
}
    int maxSatisfaction(vector<int>& satisfaction) {
      n=satisfaction.size();
      sort(satisfaction.begin(),satisfaction.end());
      memset(dp,-1,sizeof(dp));
      return solve(0,1,satisfaction)  ;
    }
};
int main(){
    Solution s;
    vector<int>satisfaction={-1,-8,0,5,-9};
    cout<<s.maxSatisfaction(satisfaction);
    return 0;
}

