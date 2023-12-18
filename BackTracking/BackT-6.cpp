// performing combination sum problems--->
// using the backtraking khandani template:
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>>ans;
void solve(int st,vector<int>& candidates,vector<int> & temp,int target){
    // base cases
    // agr target hi 0 hogaya iska matlb hume mil gaya hai combination now we can push it into the main vector and exit.
    if(target==0){
        ans.push_back(temp);
        return;
    }
    if(target<0)return;
    if(st==candidates.size())return;
    // nahi le rahe pahle toh age chlte rahe 
    solve(st+1,candidates,temp,target);
    // agr humne pahla wala dala uske bad age chle
    temp.push_back(candidates[st]);
    // kyuki humne upar element dala h toh hum target m s minus kardenge
    solve(st,candidates,temp,target-candidates[st]);
    // phir ek bar backtrack bhi karenge or purani value dal denge
    temp.pop_back();
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(0,candidates,temp,target);
        return ans;
        
    }
};
// In this code you will be getting time limit exceeded so you have to memoize.
class Solution {
public:
int t[201][1001];
int solve(int st,vector<int>& nums,int target,int n){
    // base case
    if(target==0){
        return 1;
    }
    if(st>=n|| target<0)return 0;
    if(t[st][target]!=-1) return t[st][target];
    // pahle take karlo
    int take=solve(0,nums,target-nums[st],n);
    // when we reject the 
    int reject=solve(st+1,nums,target,n);

    return t[st][target]= take+reject;
}
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums,target,n);
    }
};

int main(){

return 0;
}