// Reverse words in a string.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string finl="";
         string temp="";
        vector<string> ans;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                temp="";
            }
            while(s[i]!=' '&& i<s.length()){
                temp+=s[i];
                i++;
            }
            if(temp!="")ans.push_back(temp);
            temp="";
        }
        for(int i=ans.size()-1;i>=0;i--)
        {
            finl+=ans[i];
            if(i!=0)
                finl+=' ';
        }

        return finl;
    }
};
int main(){

return 0;
}