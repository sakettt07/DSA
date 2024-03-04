// more questions on siding window.
// Q---- Length of the longest alphabetical continuous substring
// Q--- maximum vowel present in the specific window size.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        set<char>st={'a','e','i','o','u'};
        int cnt=0,ans=0,i=0,j=0;
        int n=s.size();
        while(j<n){
            if(st.count(s[j])){
                cnt++;
            }
            if(j-i+1==k){
                ans=max(ans,cnt);
                while(j-i+1==k){
                    if(st.count(s[i])){
                        cnt--;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
class Solution {
public:

// for strings to integer we can use string -0(classic method)
    int longestContinuousSubstring(string s) {
        int ans=1,f=1;  //initializin the ans and the string by 1 because there will be atleast 1 char.
        for(int i=1;i<s.size();i++){
            if((s[i]-'0') -(s[i-1]-'0')==1){
                f++;
                ans=max(ans,f);
            }
            // the above if is checking that if 'b'-'a'=1 or not ans so on if equal that means 
            // that we have continuous string of character o the count is incremented
            else{
                f=1;
            }
        }
        return ans;
        
    }
};
int main(){

return 0;
}