// Leetcode Hard First Missing Positive.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// trying the map version for this.
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<int> mp(n+1,-1);
        for(int i=0;i<n;i++) if(nums[i]>0 && nums[i]<=n)mp[nums[i]]++;
        int i=0;
        for(i=1;i<=n;i++) if(mp[i]==-1) break;
        return i;
    }
};
int main(){

return 0;
}