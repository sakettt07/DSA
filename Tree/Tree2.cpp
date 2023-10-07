// some basic most used questons on trees:
// Height of the B.T
// Diameter of B.T
// Check if tree is balanced or not
// leetcode question(Same tree).
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int data;
    struct Node* left;
    struct Node* right;
    int height(struct Node* node){
        if(node==NULL){
            return 0;
        }
        int left=height(node->left);
        int right=height(node->right);
        int ans=max(left,right)+1;
        return ans;
    }
    int diameter(struct Node* node){
        if(node==NULL){
            return 0;
        }
        int op1=diameter(node->left);
        int op2=diameter(node->right);
        int op2=height(node->left)+1+height(node->right);
    }
    bool isBalanced(Node *root){
        if(root==NULL){
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool difference=abs(height(root->left)-height(root->right)) <=1;
        if(left&& right&& diff){
            return true;
        }
        else{
            return false;
        }
    }
    bool isIdentical(Node *r1,Node *r2){
        if(r1==NULL && r2==NULL){ 
            return true;
        }
        if(r1==NULL && r2 !=NULL){
            return false;
        }
        if(r1 !=NULL && r2 ==NULL){
            return false;
        }
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        bool value=r1->data == r2->data;
        if(left&& right&& value){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

return 0;
}