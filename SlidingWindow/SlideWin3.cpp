// Minimum window substring.its a hard problem
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //Listing all the iterations
        int i=0,j=0;
        int s1=s.length();
        int s2=t.length();
        int counter=s2;
        int subi=0;
        int minWin=INT_MAX;
        // Storing the freq of smallest string inside a map.
        map<char,int>mp;
        for(char &c:t){
            mp[c]++;
        }

        while(j<s1){
            char c1=s[j];
            // we want the character
            if(mp[c1]>0){
                counter--;
            }
            mp[c1]--;
            // window shrinking time
            while(counter==0){
                if(minWin>j-i+1){
                    minWin=j-i+1;  //saving the new window size.
                    subi=i;    //saving the string index for the last step.
                }
                // reverse case will be handled
                char chi=s[i];
                mp[chi]++;
                if(mp[chi]>0)counter++;
                i++;
            }
            j++;
        }
            return minWin==INT_MAX ? "":s.substr(subi,minWin);

    }
};
int main(){

return 0;
}