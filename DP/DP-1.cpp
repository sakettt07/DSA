// Its my Dp day-1
// There are some prerequisite for the dynamic programming :-> Recursion
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

// the code written below is the top down - Recursion +memoization Dp approach.
int fib(int n,vector<int> &dp){
        if(n<=1){
                return n;
        }
        if(dp[n]!=-1){
                return dp[n];
        }
        dp[n]= fib(n-1,dp)+fib(n-2,dp);
        return dp[n];
}
int main()
{
        int n;
        cin>>n;
        vector<int>dp(n+1);
        for(int i=0;i<=n;i++) dp[i]=-1;

        cout<< fib(n,dp)<<endl;
        return 0;
}