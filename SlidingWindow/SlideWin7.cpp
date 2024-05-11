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

// Fruit into Basket
class Solution {
public:
// tryin with the classic sliding window approach.
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();

        int i=0,j=0;
        unordered_map<int,int> mp;
        int cntF=0,maxi=INT_MIN;
        while(j<n){
            if(mp.size()<=2){
            mp[fruits[j]]++;
            cntF++;
              j++;
            }
            if(mp.size()>2){
                 cntF--;
                maxi=max(maxi,cntF);
               
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                mp.erase(fruits[i]);
                i++;  
            }
          
        }
         maxi=max(maxi,cntF);
        return maxi;
        
    }
};

int main(){

return 0;
}