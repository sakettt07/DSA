#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
        long long int pro=1;   //product karte rahenge isme.
        int n=nums.size();
        if(k==1)return 0;      //agr k is 1 then subarray kya hi banega khamkha.
        if(n==1)return (nums[0]<k?1:0);
        int cnt=0;   // jo total apne m add karta jaega.
        while(j<n){
            pro*=nums[j];
            while(pro>=k && i!=n){
                pro=pro/nums[i];         // window size kam karte ja rahe h.
                i++;
            }
            if(pro<k){
                cnt+=j-i+1;
            }
            j++;
        }
        return cnt;
    }
};
int main(){

return 0;
}