// Contructing the tree if the traversals are given:-->
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void NodeToNode(map<int,int>&mp,vector<int> inorder){
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
    }
TreeNode* Tree(vector<int>preorder,vector<int>inorder,int &pIndex,int start,int end,int n,int size,map<int,int> &mp){

        if(pIndex>=size || start>end){
            return NULL;
        }
        int element=preorder[pIndex++];
        int idx=mp[element];
        TreeNode* root=new TreeNode(element);

        root->left=Tree(preorder,inorder,pIndex,start,idx-1,n,size,mp);

        root->right=Tree(preorder,inorder,pIndex,idx+1,end,n,size,mp);

        return root;
    }





    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int end=inorder.size()-1;
        int size=preorder.size();
        map<int,int> mp;
        NodeToNode(mp,inorder);
        int pIndex=0;
        //start=0
        TreeNode* ans= Tree(preorder,inorder,pIndex,0,end,size-1,size,mp);
        return ans;
    }
};
int main(){

return 0;
}