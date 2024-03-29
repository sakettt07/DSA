// in this file we are doing a couple of LC questions based on linked list.
// Delete the middle node of the linked list.
// Remove the Nth Node from the Linked list.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode *temp=head;
        ListNode *trck=head;
        int n=0,mid=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        mid=n/2;
        for(int i=0;i<mid-1;i++){
            trck=trck->next;        //isse kya hua trck agaya mid s ek pahle
        }
        temp=trck->next->next; //temp mid k just bad m agayaa.
        trck->next=temp;    // basically track save karke delete hogaya
        return head; 
    }
};
class Solution {
public:
int lengthh(ListNode *head){
    ListNode *temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=lengthh(head);
        int pos=l-n;
        int cnt=0;
        if(pos==0){
            head=head->next;
            return head;
        }
        ListNode *prev=head;
        ListNode *curr=head;
        while(curr!=NULL){
            if(cnt==pos){
                prev->next=curr->next;
                curr->next=NULL;
                break;
            }
            else{
                prev=curr;
                curr=curr->next;
                cnt++;
            }
        }
        return head;
    }
};
int main(){

return 0;
}