// Taking the tree data structures forward we will be starting bst in Day-92
#include<bits/stdc++.h>
using namespace std;

// Sari declarations has been done here
class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

// Printing wala sara mamlaaaaa
void levelOrder(Node *root)
{
    queue<Node *> qe;
    qe.push(root);
    qe.push(NULL);
    while (!qe.empty())
    {
        Node *temp = qe.front();

        qe.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!qe.empty())
            {
                qe.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                qe.push(temp->left);
            }
            if (temp->right)
            {
                qe.push(temp->right);
            }
        }
    }
}
void inorder(Node *root)
{
    // base
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// The main function which is maintaining all the logic of the BST:-->
Node* insertBST(Node* root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertBST(root->right,d);
    }
    else{
         root->left=insertBST(root->left,d); 
    }
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
     root =insertBST(root,data);
        cin>>data;
    }
}
int main(){
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    cout<<"Printing the BST using level order traversals"<<endl;
    levelOrder(root);
    cout<<"Printing all the traversals"<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);

return 0;
}