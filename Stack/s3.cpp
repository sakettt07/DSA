#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        solveBoard(board,n);
    }
    bool notclash(char num,int i,int j,vector<vector<char>>& board,int n){
        for(int k=0;k<n;k++){
            if(board[i][k]==num) return false;
            if(board[k][j]==num) return false;
        }
        int s=sqrt(n);
        int startrow=i-i%s;
        int startcol=j-j%s;
        for(int r=startrow;r<startrow+s;r++){
            for(int c=startcol;c<startcol+s;c++){
                if(board[r][c]==num) return false;
            }
        }
        return true;
    }
    bool solveBoard(vector<vector<char>>& board,int n){
        bool flag=false;
        int i,j;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(board[i][j]=='.'){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(i==n && j==n) return true;
        
        for(int num=1;num<=n;num++){
            if(notclash(num+48,i,j,board,n)){
                board[i][j]=num+48;
                if(solveBoard(board,n))return true;
                board[i][j]='.';
            }
        }
        return false;

    }
};
int main(){

return 0;
}