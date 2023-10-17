// Taking the tree data structures forward we will be starting bst in Day-92
#include<bits/stdc++.h>
using namespace std;

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
    cout<<"Printing the BST"<<endl;
    levelOrder(root);

return 0;
}