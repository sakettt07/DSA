// Searching the given node in the binary search tree
// we can do it by two methiods recursively and iteratively

// perforking deletion int his file only --
#include<bits/stdc++.h>
using namespace std;
// using recursion
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        
        if(root->val == val)
            return root;
        else if(val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
        
        return root;
    }
};
// Iterative solution
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {   
        TreeNode *curr = root;
        while(true){
            if(curr == NULL || val == curr->val){
                break;
            }
            else if(val < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return curr;
    }
};
int main(){

return 0;
}