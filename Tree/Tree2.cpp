// some basic most used questons on trees:
// Height of the B.T
// Diameter of B.T
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
};

int main(){

return 0;
}