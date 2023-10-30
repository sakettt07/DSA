// what is a balanced bst- it is a property of a bst in which
// when we check every node of the tree then we have to make shure the that the height of the tree is not more than  -1.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void inorder(TreeNode* root,vector<int> &v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
TreeNode* banao(int s,int e,vector<int> inorderarr){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    TreeNode* root=new TreeNode(inorderarr[mid]);
    root->left=banao(s,mid-1,inorderarr);
    root->right=banao(mid+1,e,inorderarr);
    return root;

}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorderarr;
        inorder(root,inorderarr);
        return banao(0,inorderarr.size()-1,inorderarr);
    }
};
int main(){

return 0;
}