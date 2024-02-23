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
int main(){

return 0;
}