// Starting with the backtracking its Day-1
// Learning this method of solving problem with the help of a question which is rat in a maze.
#include <bits/stdc++.h>
bool isSafe(int newX, int newY, vector<vector<bool>> & isVisited, vector<vector<int>> & arr, int n) {
    if((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && isVisited[newX][newY] == false && arr[newX][newY] != 0)
        return true;
    return false;
}
void solve(int x, int y, vector<vector<int>> & arr, int n, vector<string> & ans, vector<vector<bool>> & isVisited, string path) {
    if(x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    isVisited[x][y] = true;
    // for the downward direction
    if(isSafe(x + 1, y, isVisited, arr, n))
        solve(x + 1, y, arr, n, ans, isVisited, path + 'D');
        // for the left position
    if(isSafe(x, y - 1, isVisited, arr, n))
        solve(x, y - 1, arr, n, ans, isVisited, path + 'L');
        // for the right position
    if(isSafe(x, y + 1, isVisited, arr, n))
        solve(x, y + 1, arr, n, ans, isVisited, path + 'R');
        // for the upward position
    if(isSafe(x - 1, y, isVisited, arr, n))
        solve(x - 1, y, arr, n, ans, isVisited, path + 'U');
    isVisited[x][y] = false;
}
vector<string> searchMaze(vector<vector<int>> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<bool>> isVisited(n, vector<bool>(n, 0));
    string path = "";
    if(arr[0][0] == 0)
        return ans;
    solve(0, 0, arr, n, ans, isVisited, path);
    return ans;
}
int main(){
    int n = 4;
    vector<vector<int>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    // Call the searchMaze function
    vector<string> result = searchMaze(arr, n);

    // Display the result
    if (result.empty()) {
        cout << "No valid paths found." << endl;
    } else {
        cout << "Paths found:" << endl;
        for (const string& path : result) {
            cout << path << endl;
        }
    }
    return 0;
}