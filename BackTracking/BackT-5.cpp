// In this i have performed backtracking based question 
// 1---> combinations
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>>list;
void combi(int st,int k,vector<int>&result,int n){
    if(k==0){
        list.push_back(result);
        return;
    }
    if(st>n)return;
    result.push_back(st);
    combi(st+1,k-1,result,n);
    result.pop_back();
    combi(st+1,k,result,n);
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>result;
        combi(1,k,result,n);
        return list;
    }
};
int main(){

return 0;
}