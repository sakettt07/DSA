// Sliding window -potd ---: Count-subarrays-where-max-element-appears-at-least-k-times
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int i=0,j=0;
        long long int cnt=0;
        int n=nums.size();
        int maxel=*max_element(nums.begin(),nums.end());
        // taking out the maximum element from the array.
        while(j<n){
            mpp[nums[j]]++;     //pushing the elements inside the map.
            // the below condition is for shrinking the window when the condition meets caused we have to find the subarrays.
            while(mpp[maxel]>=k){
                cnt+=(n-j);    // yeh hum total subarrays dega
                mpp[nums[i]]--;     //kyuki window shrink ho rahi h toh hum jis element s hate uski freq minus kardenge.
                i++;
            }
            j++;
        }
        return cnt;
    }
};
int main(){

return 0;
}