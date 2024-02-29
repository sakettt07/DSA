
// Question-2 Permutation in strings
// Question-3 Minimum Size Subarray Sum
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
bool allZero(vector<int>& count) {
        return count==vector<int>(26, 0);
    }

	int search(string pat, string txt) {
	    int k = pat.size();
	    vector<int> count(26, 0);
	    for(char &ch : pat) {
	        count[ch-'a']++;
	    }
	    int i = 0, j = 0;
	    int n = txt.size();
	    // int result = 0;
	    while(j < n) {
	        int idx = txt[j]-'a';
	        count[idx]--;
	        
	        if(j - i + 1 == k) {
	            if(allZero(count)) {
	                return true;
	            }
	            
	            count[txt[i]-'a']++;
	            i++;
	        }
	        j++;
	    }
	    return false;
	}

};
// Solution to the Question-3
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,i=0,j=0;
        int n=nums.size(),minLen=INT_MAX;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                minLen=min(minLen,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return minLen==INT_MAX?0:minLen;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        string pat,txt;
        cin>>txt>>pat;
        Solution ob;
        auto ans=ob.search(pat,txt);
        cout<<ans<<endl;
    }
return 0;
}