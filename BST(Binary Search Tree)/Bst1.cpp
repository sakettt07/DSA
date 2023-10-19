// Taking the tree data structures forward we will be starting bst in Day-92
#include <bits/stdc++.h>
using namespace std;

// Sari declarations has been done here
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
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
Node *insertBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertBST(root->right, d);
    }
    else
    {
        root->left = insertBST(root->left, d);
    }
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
}
Node *minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxVal(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBst(Node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        // for 0 childd
        if(root->left ==NULL && root->right ==NULL){
            delete root;
            return root;
        }
        // for 1 child at both side
        if(root->left !=NULL && root->right ==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left ==NULL && root->right !=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        // for 2 child(called a sub BST)
        if(root->left !=NULL && root->right !=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBst(root->right,mini);
            return root;
        }

    }
    else if(root->data>val){
        root->left=deleteFromBst(root->left,val);
        return root;
    }
    else{
        root->right=deleteFromBst(root->right,val);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST" << endl;
    takeInput(root);
    cout << "Printing the BST using level order traversals" << endl;
    levelOrder(root);
    cout << "Printing all the traversals" << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout<<endl;

    cout << "min value is: " << minVal(root)->data << endl;
    cout << "max value is: " << maxVal(root)->data << endl;

    cout<<"performing deletion"<<endl;
    root=deleteFromBst(root,20);

    return 0;
}