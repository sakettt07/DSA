// In this file i have started off with the new non linear data structure (Tree);
// Implementation -WE build the tree using recursion in this
// Level order traversal (this will helps us to print the tree);
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data :" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right of " << data << endl;
    root->right = buildTree(root->right);
}
// we also called it breadth first search
void levelOrder(node *root)
{
    queue<node *> qe;
    qe.push(root);
    qe.push(NULL);
    while (!qe.empty())
    {
        node *temp = qe.front();

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
// To print the tree in reverse order using for loop fron the height of the tree iterating reverse.

// void reverseLevelOrder(node* root)
// {
//     int h = height(root);
//     int i;
//     for (i=h; i>=1; i--)
//         printGivenLevel(root, i);
// }

void inorder(node *root)
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
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// how to build a tree from traversals
void buildfromlevelorder(node *root)
{
    queue<node*> q;
    cout << "Enter the data for the root" << endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter left node for :" << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter right node for :" << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;
    buildfromlevelorder(root);
    levelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    /*
        root = buildTree(root);

        cout << " Printing the tree" << endl;
        levelOrder(root);

        // The data for the dry run tree
        // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        cout<<endl;
        cout<<"The inorder traversal for the above tree is :";
        inorder(root);
        cout<<endl;
        cout<<"The preorder traversal for the above tree is :";
        preorder(root);
        cout<<endl;
        cout<<"The postorder traversal for the above tree is :";
        postorder(root);
        */

    return 0;
}