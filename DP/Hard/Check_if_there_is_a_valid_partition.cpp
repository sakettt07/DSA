#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;
    int dp[100001];
    // brute force - recursion solution
    bool solve(int i, vector<int>& nums) {
        if (i >= N) {
            return true;
        }
        bool result = false;
        if(dp[i]!=-1){
            return dp[i];
        }
        // RULE -1 when two adjacent elements are equal.
        if (i + 1 < N && nums[i] == nums[i + 1]) {
            result = solve(i + 2, nums);
        }
        if (result == true) {
            return true;
        }
        // RULE -2 when three adjacent elements are equal.
        if (i + 2 < N && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) {
            result = solve(i + 3, nums);
        }
        if (result == true) {
            return true;
        }
        // RULE -3 when three adjacent elements are contiguous and have a
        // difference of 1 between them.
        if (i + 2 < N && nums[i + 1] - nums[i] == 1 &&
            nums[i + 2] - nums[i + 1] == 1) {
            result = solve(i + 3, nums);
        }
        return dp[i]= result;
    }
    bool validPartition(vector<int>& nums) {
        N = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, nums);
    }
};
int main(){
    Solution s1;
    vector<int>nums={1,1,1,2,3,4,5,5,5};
    bool result=s1.validPartition(nums);
    cout << (result ? "Valid Partition" : "Invalid Partition") << endl;

return 0;
}