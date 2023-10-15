// MOrris Traversal technique ya we can say algorithm.
// In this algorithm we maintain a link of the previous visited node of a tree and its Time Complexity is-O(n)
// And its Space Complexity is O(1);
// It is used to be a best algorithm technique
// Based on threaded binary tree
#include<bits/stdc++.h>
using namespace std;

class node  
{  
    public: 
    int data;  
    node *left, *right;  
};  
node* newNode(int data)  
{  
    node* temp = new node(); 
    temp->data = data;  
    temp->left = temp->right = NULL;  
    return temp;  
}  
void morrisTraversalPreorder(node* root)  
{  
    while (root)  
    {  
        // If left child is null, print the current node data. Move to  
        // right child.  
        if (root->left == NULL)  
        {  
            cout<<root->data<<" ";  
            root = root->right;  
        }  
        else
        {  
            // Find inorder predecessor  
            node* current = root->left;  
            while (current->right && current->right != root)  
                current = current->right;  
  

            if (current->right == root)  
            {  
                current->right = NULL;  
                root = root->right;  
            }  

            else
            {  
                cout<<root->data<<" ";  
                current->right = root;  
                root = root->left;  
            }  
        }  
    }  
}  
void preorder(node* root)  
{  
    if (root)  
    {  
        cout<<root->data<<" ";  
        preorder(root->left);  
        preorder(root->right);  
    }  
}  
int main(){
    node* root = NULL;  
  
    root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
  
    root->right->left = newNode(6);  
    root->right->right = newNode(7);  
  
    root->left->left->left = newNode(8);  
    root->left->left->right = newNode(9);  
  
    root->left->right->left = newNode(10);  
    root->left->right->right = newNode(11);  
    
  
    cout<<endl;  
    preorder(root);  
  
    return 0;  

return 0;
}