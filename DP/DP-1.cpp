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
// writing the bottomm up approach for the same.
int main()
{
        int n;
        cout<<"Enter any number : ";
        cin>>n;
        // vector<int>dp(n+1);
        // for(int i=0;i<=n;i++) dp[i]=-1;

        // cout<< fib(n,dp)<<endl;

        // bottom-up

        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
            cout<<dp[n];
        

        // space optimaization technique

        
        return 0;
}