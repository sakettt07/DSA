#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // Go level by level BFS
        queue<TreeNode*>q;
        q.push(root);
        int lvl=1,ans=1;
        int maxi=INT_MIN;
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(sum>maxi){
                maxi=sum;
                ans=lvl;
            }
            lvl++;
        }
        return ans;
    }
};
int main(){
    Solution s1;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    cout << s1.maxLevelSum(root) << endl;
return 0;
}