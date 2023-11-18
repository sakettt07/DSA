#include <iostream>
using namespace std;

// List template
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next) : val(val), next(next) {}; 

    ~ListNode() {
        if(next) {
            delete next;
        }
    }
};
struct TreeNode {
    int val;
    TreeNode* left; TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {};
    ~TreeNode() {
        if(left) {
            delete left;
        }
        if(right) {
             delete right;
        }
    }
};

void printList(ListNode* head) {
    if(head) {
        cout<<head->val<<' ';
        printList(head->next);
    }
}

// Method to print tree using preOrder traversal
void printTree(TreeNode* root) {
    if(root) {
        cout<<root->val<<' ';
        printTree(root->left);
        printTree(root->right);
    }
}

// Method helper
bool checkForPath(TreeNode* root, ListNode* head) {
    if(!head)
        return true;

    if(!root || root->val != head->val)
        return false;
    return checkForPath(root->left, head->next) || checkForPath(root->right, head->next);
}

bool isSubPath(ListNode* head, TreeNode* root) {

    if(!head)
        return true;


    if(!root)
        return false;


    if(checkForPath(root, head))
        return true;

    // Recursively check from each node of the tree
    return isSubPath(head, root->left) || isSubPath(head, root->right);
}

// Driver code
int main() {
    // Creating list, connecting nodes and initializing their data
    ListNode* head = new ListNode(4, new ListNode(5, new ListNode(8, nullptr)));

    // Creating tree, connecting nodes and initializing their data
    TreeNode* c5 = new TreeNode(8);
    TreeNode* c4 = new TreeNode(5, nullptr, c5);
    TreeNode* c3 = new TreeNode(4, nullptr, c4);
    TreeNode* c2 = new TreeNode(3);
    TreeNode* c1 = new TreeNode(2, nullptr, c2);
    TreeNode* rt = new TreeNode(1, c1, c3);

    // Print list
    printList(head); cout<<'\n';

    // Print tree
    printTree(rt); cout<<'\n';

    // Verification call
    if(isSubPath(head, rt))
        cout<<"The linked list exist as a path in the binary tree!";
    else
        cout<<"The linked list does not exist as a path in the binary tree!";
    delete head;

    delete rt;

    return 0;
}