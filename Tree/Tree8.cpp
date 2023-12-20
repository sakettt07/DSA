// code for the problem Binary Tree Maximum Path Sum----->
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int maxsum;
int solve(TreeNode* root){
    // base case condition
    // if there is no root then what will we checking in the tree.
    if(!root)return NULL;
    // call for the left part
    int l=solve(root->left);
    // call for the right part
    int r=solve(root->right);
// case 1 adding all the values of the downward path
    int downgood=l+r+root->val;
    // checking for the negative nodes if left part contains negative vice versa then maximum among them will be taken
    int anyone=max(l,r)+root->val;
    // if the root itself is good or the maximum then take the root.
    int rootgood=root->val;
    maxsum=max({maxsum,downgood,anyone,rootgood});
    return max(anyone,rootgood);

}
    int maxPathSum(TreeNode* root) {
        // assuming the maxsum to be the minimum in the starting
        maxsum=INT_MIN;
        // call for the function 
        solve(root);
        return maxsum;
    }
};
int main(){

return 0;
}