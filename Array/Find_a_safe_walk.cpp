// Coding contest question more like a 2D array question matrix based.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size();
        int col = grid[0].size();

        //directions for moving right, down, left, up
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
// using the bfs method
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, health - grid[0][0]});
        
        // visited array to keep track of the max health
        vector<vector<int>> visited(row, vector<int>(col, -1));
        visited[0][0] = health - grid[0][0];
        
        while (!q.empty()) {
            auto [pos, currHealth] = q.front();
            q.pop();
            
            int x = pos.first;
            int y = pos.second;
            
            // base case when we reach the finish then end.
            if (x == row - 1 && y == col - 1 && currHealth > 0) {
                return true;
            }
            
            // Explore all 4 possible directions
            for (int i = 0; i < 4; ++i) {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];
                
                // Check if the new cell is within bounds
                if (newX >= 0 && newY >= 0 && newX < row && newY < col) {
                    int newHealth = currHealth - grid[newX][newY];
                    
                    // going further if we have the health.
                    if (newHealth > 0 && newHealth > visited[newX][newY]) {
                        visited[newX][newY] = newHealth;
                        q.push({{newX, newY}, newHealth});
                    }
                }
            }
        }
    
        return false;
    }
};
int main(){

return 0;
}