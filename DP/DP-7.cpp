// Longest common subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int m,n;
int t[1001][1001];

int solve(string &s1,string &s2,int i,int j){
    if(i>=m||j>=n)return 0;
    if(s1[i]==s2[j])return 1+solve(s1,s2,i+1,j+1);
    if(t[i][j]!=-1)return t[i][j];
    int inci=solve(s1,s2,i+1,j);
    int incj=solve(s1,s2,i,j+1);
    return t[i][j]=max(inci,incj);
}
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.length();
        n=text2.length();
        memset(t,-1,sizeof(t));
        return solve(text1,text2,0,0);

    }
};
int main(){

return 0;
}