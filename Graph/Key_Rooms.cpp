#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // trying the classic BFS traversal.
        queue<int> qu;
        qu.push(0); // initial room key is true and pushed
        vector<bool> visited(rooms.size(), false);
        while (!qu.empty()) {
            int frontN = qu.front();
            visited[frontN] = true;
            for (int i = 0; i < rooms[frontN].size(); i++) {
                if (visited[rooms[frontN][i]] ==
                    false) { // pushing the newighbouring related to the
                             // previous key.
                    qu.push(rooms[frontN][i]);
                }
            }
            qu.pop();
        }
        // if any key is false then false. which means we can't open the rooms
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    cout << s.canVisitAllRooms(rooms) << endl;
return 0;
}