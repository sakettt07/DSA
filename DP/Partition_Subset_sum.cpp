#include<bits/stdc++.h>
using namespace std;
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool solve(int N,int arr[],int target,int indx,vector<vector<int>> &dp){
    // base case.
    if(indx>=N)return 0;
    if(target<0)return 0;
    if(target==0)return 1;
    if(dp[indx][target]!=-1){
        return dp[indx][target];
    }
    
    bool take=solve(N,arr,target-arr[indx],indx+1,dp);
    bool notTake=solve(N,arr,target-0,indx+1,dp);
    return dp[indx][target]= take||notTake;
}
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0;i<N;i++){
            total+=arr[i];
        }
        if(total&1)return 0;
        int target=total/2;
        vector<vector<int>>dp(N,vector<int>(target+1,-1));
        return solve(N,arr,target,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}