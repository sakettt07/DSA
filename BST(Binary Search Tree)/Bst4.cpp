// performing Merge two binary search trees.
#include<bits/stdc++.h>
using namespace std;

void inorder(TreeNode* root,vector<int> &in1){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    in1.push_back(root->data);
    inorder(root->right);
}
vector<int>mergedarray(vector<int>a,vector<int>b){
    vector<int> ans(a.size()+b.size());

    int i=0,j=0,k=0;
    while(i<a.size()&& j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i];
        i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }
    }
    while(i<a.size()){
        ans[k++]=a[i];
        i++;
    }
    while(j<b.size()){
        ans[k++]=b[j];
        j++;
    }
    return ans;
}
TreeNode* inorderToBST(vector<int> &inorder, int start, int end){

    if(start > end) return(NULL);
    int mid = (start+end)/2;
    TreeNode* root = new TreeNode (inorder[mid]);
    root->left = inorderToBST(inorder, start, mid-1);
    root->right = inorderToBST(inorder, mid+1, end);
    return(root);
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Step 1 me inorder store karalo of both the trees.
    vector<int>bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    vector<int>mergedarray=mergearrs(bst1,bst2);
    TreeNode* root = inorderToBST(mergedarray, 0, mergedarray.size()-1);
    vector<int> answer;
    inorder(root, answer);
    return(answer);

}
int main(){

return 0;
}