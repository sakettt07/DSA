// It a LC contest question 
// Minimum operations to make median of an array equals to k
#include<bits/stdc++.h>
using namespace std;

int main(){
    class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = n / 2;
        long diff = k - nums[median];
        long oper = 0;       //total operations usedddd
        for (int i = 0; i < n; i++) {
            
//             for smaller than i
            if (nums[i] < k && median <= i) {
                oper = oper + (k - nums[i]);
            }
            
//             this condition will run till median index is greater than i.
            else if (nums[i] > k && median >= i) {
                oper = oper + (nums[i] - k);
            }
        }
        return oper;
    }
};

return 0;
}