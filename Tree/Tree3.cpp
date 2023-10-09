// Some more wuestions on trees
// it includes mostly views question;
#include<bits/stdc++.h>
using namespace std;

// To print the value of trees in the zig zag level.
class solution{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>v(size);
            for(int i=0;i<size;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                int index=leftToRight  ?i:size-i-1;
                v[index]=frontNode->val;

                if(frontNode->left)
                q.push(frontNode->left);
            
            if(frontNode->right)
                q.push(frontNode->right);
            }
            leftToRight=!leftToRight;
            ans.push_back(v);
        }
        return ans;
    }

    // TO get the bottom left node of the treee(using level order traveral in reverse order)
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* node;
        while(!q.empty()){
            node=q.front();
            q.pop();
            if(node->right){
                q.push(node->right);
            }
            if(node->left){
                q.push(node->left);
            }
        }
            return node->val;
    }
};
int main(){

return 0;
}