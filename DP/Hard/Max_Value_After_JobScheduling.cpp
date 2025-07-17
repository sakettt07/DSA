#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int n;
int dp[50001];    // memoizing for the changing index.
int genNextIdx(vector<vector<int>>& array, int l,int target){
    int r=n-1;
    int result=n+1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(array[mid][0]>=target){  // this means we can take this job as its starting time is greater.
        result=mid;
        r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return result;
}
    int solve(vector<vector<int>>& array, int idx) {
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int nextIdx=genNextIdx(array,idx+1,array[idx][1]);
        int notTake=solve(array,idx+1);
        int take=array[idx][2]+solve(array,nextIdx);     
        return dp[idx]= max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>>array(n,vector<int>(3,0));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            array[i][0]=startTime[i];
            array[i][1]=endTime[i];
            array[i][2]=profit[i];
        }
        auto comp = [&](auto& a1, auto& b1) {
            return a1[0] < b1[0];
        };
        sort(array.begin(),array.end(),comp);
        return solve(array,0);
    }
};
int main(){

return 0;
}