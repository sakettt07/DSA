#include<bits/stdc++.h>
using namespace std;
// type:2
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == NULL)
            return root;

        queue<TreeNode*> temp;
        temp.push(root);

        root->val = 0;

        while (!temp.empty()) {
            int lsize = temp.size();
            int totalSum = 0;

            unordered_map<TreeNode*, int> cousins;
            for (int i = 0; i < lsize; i++) {
                TreeNode* node = temp.front();
                temp.pop();
                int childsum = 0;

                if (node->left != NULL) {
                    temp.push(node->left);
                    childsum += node->left->val;
                }

                if (node->right != NULL) {
                    temp.push(node->right);
                    childsum += node->right->val;
                }

                cousins[node] = childsum;
                totalSum += childsum;
            }

            for (auto& x : cousins) {
                TreeNode* node = x.first;
                int childsum = x.second;

                if (node->left != NULL)
                    node->left->val = totalSum - childsum;

                if (node->right != NULL)
                    node->right->val = totalSum - childsum;
            }
        }

        return root;
    }
};
// type :1
class Solution {
public:
    // Applying the basic BFS traversal.
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int s = qu.size();
            bool foundX = false, foundY = false;
            while (s--) {
                TreeNode* curr = qu.front();
                qu.pop();

                if (curr->val == x) {
                    foundX = true;
                }
                if (curr->val == y) {
                    foundY = true;
                }
                // now check whether they have same parent or not if this
                // happens then return false.
                if (curr->left && curr->right) {
                    if ((curr->left->val == x && curr->right->val == y) ||
                        (curr->left->val == y && curr->right->val == x))
                        return false;
                }

                if (curr->left) {
                    qu.push(curr->left);
                }
                if (curr->right) {
                    qu.push(curr->right);
                }
            }
            if (foundX && foundY) {
                return true;
            }
        }
        return false;
    }
};
int main(){

return 0;
}