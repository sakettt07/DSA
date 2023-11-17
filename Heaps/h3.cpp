// So in this file a question is solved which is named as;
// Is Binary tree heap 
// Merge two binary max heaps-
    //   Simple approach is to merge the arrays and make a array c from a and b then make the max heap of the array c and apply the heapify function on it. 


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countNodes(struct Node* root) {
        if(root == NULL)
            return 0;
        int ans = 1 + countNodes(root -> left) + countNodes(root -> right);
        return ans;
    }
    bool isCBT(struct Node* root, int index, int totalCount) {
        if(root == NULL)
            return true;
        if(index >= totalCount)
            return false;
        else
        {
            bool left = isCBT(root -> left, 2 * index + 1, totalCount);
            bool right = isCBT(root -> right, 2 * index + 2, totalCount);
            return left && right;
        }
    }
    bool isMaxOrder(struct Node* root) {
        if(root -> left == NULL && root -> right == NULL)
            return true;
        if(root -> right == NULL)
        {
            return (root -> data > root -> left -> data);
        }
        else
        {
            bool left = isMaxOrder(root -> left);
            bool right = isMaxOrder(root -> right);
            if(left && right && root -> data > root -> left -> data && root -> data > root -> right -> data)
                return true;
            else
                return false;
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int totalCount = countNodes(tree);
        if(isCBT(tree, index, totalCount) && isMaxOrder(tree))
            return true;
        return false;
    }

    // Q2 (solution)
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        
        vector<int>ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        int size=ans.size();
        
        for(int i=size/2-1;i>=0;i--){
        heapify(ans,size,i);
    }
    return ans;


};
int main(){

return 0;
}