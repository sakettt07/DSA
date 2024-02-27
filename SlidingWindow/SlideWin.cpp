// Starting off with the new problem solver method.
// Question-1 Count the occurences of the anagrams.

// Question-2 Find all anagrams in a string.( return the index at which you are getting the anagram)
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
	    int result = 0;
	    while(j < n) {
	        int idx = txt[j]-'a';
	        count[idx]--;
	        
	        if(j - i + 1 == k) {
	            if(allZero(count)) {
	                result++;
	            }
	            
	            count[txt[i]-'a']++;
	            i++;
	        }
	        j++;
	    }
	    return result;
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