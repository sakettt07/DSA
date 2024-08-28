#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& grid2, vector<vector<int>>& grid1,int i,int j,int m,int n)
    {

        // all out of bounds condition
        if(i<0 || j<0 || i>=m || j>=n || grid2[i][j]==0)
            return true;
        bool ans=grid1[i][j]==grid2[i][j];
        grid2[i][j]=0;

        // managing all the four directionss
        ans = dfs(grid2, grid1, i+1, j, m, n) && ans;
        ans = dfs(grid2, grid1, i, j+1, m, n) && ans;
        ans = dfs(grid2, grid1, i-1, j, m, n) && ans;
        ans = dfs(grid2, grid1, i, j-1, m, n) && ans;
        return ans;
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int count =0;
        // traversing in the parent grid.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    if(dfs(grid2, grid1, i, j, m, n)){
                        count++;
                    };
                }
            }
        }
        return count;
    }
};
int main(){

return 0;
}