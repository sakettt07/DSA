#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // using hashmaps
        unordered_map<int,int>m;
        // the above hashmap will store the frequency of the character from chars
        for(auto x:chars)m[x]++;
        // the final ans set to be 0 
        int ans=0;
        // now traversin through the words array storing the frequency of the words in the same manner taking y as the inner loop variable
        for(auto x: words){
            unordered_map<int,int>n;
            for(auto y:x) n[y]++;
            bool flag=false;
            for(auto y:x){
                // this condition will checks the frequency or the presence of the word in the map
                // if present flag will be set to true
                if(m.find(y)==m.end()||n.find(y)==n.end()|| m[y]<n[y]){
                    flag=true;
                    break;
                }
            }
            // here is flag false this means word not found and add the length of the word
            if(flag==false) ans+=x.length();
        }
        return ans;
    }
};
int main(){

return 0;
}