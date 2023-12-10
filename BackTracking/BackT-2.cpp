// This file is for backtracking day-2 in which the problem n queens has been solved
#include <bits/stdc++.h>
void addSol(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
	int x = row;
	int y = col;
	// checking for the same row
	while (y >= 0)
	{
		if (board[x][y] == 1)
			return false;
		y--;
	}
	x = row;
	y = col;
	// checking for diagonals
	// for upward diagonal
	while (x >= 0 && y >= 0)
	{
		if (board[x][y] == 1)
			return false;
		y--;
		x--;
	}
	x = row;
	y = col;
	// for downward diagonal
	while (x < n && y >= 0)
	{
		if (board[x][y] == 1)
			return false;
		y--;
		x++;
	}
	return true;
}
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
	if (col == n)
	{
		addSol(board, ans, n);
		return;
	}
	// solving the first case
	for (int row = 0; row < n; row++)
	{
		if (isSafe(row, col, board))
		{
			board[i][j] = 1;
			solve(col + 1, ans, board, n);
			board[i][j] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	// Write your code here

	// create a board
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> ans;
	solve(0, ans, board, n);
	return ans;
}