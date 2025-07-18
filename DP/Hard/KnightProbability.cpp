// KNIGHT PROBLEM -      What's the problem says --> 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//memoizing
unordered_map<string,double>mp;
vector<pair<int,int>>directions={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
double solve(int row,int col,int k,int n){
    if(row < 0 || row >= n || col < 0 || col >= n){   // you have moved out of the board.
        return 0.0;
    }
    string key=to_string(k)+"_"+to_string(row)+"_"+to_string(col);
    if(k==0){  // you have moved k times.
        return 1.0;
    }
    if(mp.find(key)!=mp.end()){
        return mp[key];
    }
    double result=0;
    for(auto& dir:directions){
        int newrow=row+dir.first;
        int newcol=col+dir.second;
        result+=(double)solve(newrow,newcol,k-1,n);
    }
    return mp[key]= (double)result/8.0;
}
    double knightProbability(int n, int k, int row, int column) {
        return  solve(row,column,k,n);
    }
};
int main(){

    Solution s1;
    int n = 3, k = 2, row = 0, column = 0; // Example input
    double result = s1.knightProbability(n, k, row, column);
    cout << "Probability: " << result << endl; // Output the result
return 0;
}