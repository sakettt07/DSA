// Longest Palindromic Subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// tried with the recursion method -it results in TLE.
// Memoized the code for the two pointers
int t[1001][1001];
int solve(string &s,int l,int r){
    if(l>r)return 0;
    if(l==r)return 1;
    if(t[l][r]!=-1){
        return t[l][r];
    }
    if(s[l]==s[r]){
        return 2+solve(s,l+1,r-1);   //doing the +2 cause we are geting  two chars same
    }
    else{
        return t[l][r]=max(solve(s,l+1,r),solve(s,l,r-1));
    }
}
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        memset(t,-1,sizeof(t));
        return solve(s,0,n-1);
    }
};
int main(){

return 0;
}