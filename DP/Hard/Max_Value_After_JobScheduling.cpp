#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int n;
    int solve(vector<vector<int>>& array, int idx) {
        if(idx>=n){
            return 0;
        }
        int notTake=solve(array,idx+1);
        int take=0;     
        return max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>>array(n,vector<int>(3,0));
        for(int i=0;i<i<n;i++){
            array[i][0]=startTime[i];
            array[i][1]=endTime[i];
            array[i][2]=profit[i];
        }
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        };
        sort(array.begin(),array.end(),comp);
        return solve(array,0);
    }
};
int main(){

return 0;
}