// Popular question of the sliding window. -------Maximum Consequtive Ones 3
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// simple sliding window.
    int longestOnes(vector<int>& nums, int k) {
        int maxi=0;
        int n=nums.size();
        int i=0,j=0;
        int zerocnt=0;
        while(j<n){
            if(nums[j]==0)zerocnt++;
            while(zerocnt>k){
                if(nums[i]==0)zerocnt--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
int main(){

return 0;
}