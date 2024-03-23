// POTD question Reorder List.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// trying this problem using extra space method
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        vector<ListNode*>arr;
        while(temp){
            arr.push_back(temp);
            temp=temp->next;
        }
        // till now we have all the nodes in the vector.
        // Now we will be using two pointer and store in another vector
        vector<ListNode*>finl;
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            if(l==r){
                finl.push_back(arr[l]);
                break;
            }
           finl.push_back(arr[l]);
           finl.push_back(arr[r]);
           l++,r--; 
        }

        // Now linking the new arr to the head of the linked list
        head->next=NULL;
        temp=head;
        for(int i=1;i<finl.size();i++){
            ListNode* curr=new ListNode(finl[i]->val);  //till we are getting the new node we are making a new and inserting at the end of the head.
            temp->next=curr;
            temp=temp->next;
        }
        
    }
};
int main(){

return 0;
}