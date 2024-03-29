// Sliding window potd - Length-of-longest-subarray-with-at-most-k-frequency
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// applying the classic sliding window approach.
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int maxi=0;
        unordered_map<int,int>mpp;
        while(j<n){
            // addding up the frequency of each element present in the array.
            mpp[nums[j]]++;
            // till we are getting the frequency greater than k we shrink the window.
            while(mpp[nums[j]]>k){
                mpp[nums[i]]--;
                i++;
                // the above written condition is for shrink the window from the left.
            }
            // now finding the length till now for the longest subarry.
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};

int main(){

return 0;
}