// This file is for backtracking day-2 in which the problem n queens has been solved
#include <bits/stdc++.h>
void addSol(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
	vector<int>temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);

}
void solve(int col,	vector<vector<int>> &ans,vector<vector<int>> &board,int n){
	if(col==n){
		addSol(board,ans,n);
		return;
	}
	// solving the first case
	for(int row=0;row<n;row++){
		if(isSafe(row,col,board)){
			board[i][j]=1;
			solve(col+1,ans,board,n);
			board[i][j]=0;
		}
	}
} 

vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>>board(n,vector<int>(n,0));
	vector<vector<int>>ans;
	solve(0,ans,board,n);
	return ans;
	
}