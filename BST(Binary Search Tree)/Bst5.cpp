// This is the last file for the binary search tree in this file we are going to perform two questions :---->
// recover Binary search tree
// largest BST
#include<bits/stdc++.h>
using namespace std;

// recover a BST
class solution{
public:
vector<int>v;
int i=0;
void inorder(TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}
void check(TreeNode* root){
    if(root==NULL) return; 
    check(root->left);
    if(v[i]!=root->val){
        swap(v[i],root->val);
        i++
    }
    check(root->right);
}
void recoverTree(TreeNode* root) {
        inorder(root);
        sort(v.begin(),v.end());
        check(root);
    }
};

int main(){

return 0;
}