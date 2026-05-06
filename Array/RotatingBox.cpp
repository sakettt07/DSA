#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>>ans(n,vector<char>(m,'.'));

        //declaring variables
        int r=m-1,c=n-1;
        int r2=n-1,c2=0;
        int lastP=n-1;

        // basically the idea is that we are filiing the new array backward.
        while(r>=0){
            if(box[r][c]=='.'){
                r2--;
            }
            // this means there is a wall
            else if(box[r][c]=='*'){
                lastP=c-1;
                ans[r2][c2]='*';
                r2--;
            }
            else{
                ans[lastP][c2]='#';
                r2--;
                lastP--;
            }
            c--;  //decreasing the column

            // we have traversed the first row.
            if(c==-1){
                r--;
                c=n-1;
                r2=n-1;
                lastP=n-1;
                c2++;
            }

        }
        return ans;
    }
};
int main(){
    Solution s;
     vector<vector<char>> box = {
        {'#', '#', '*', '.', '*', '.'},
        {'#', '#', '#', '*', '.', '.'}
    };
    vector<vector<char>> ans = s.rotateTheBox(box);
    for (const auto& row : ans) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }   
    
return 0;
}