// Insert the GCD of the adjacent nodes in between the linked list.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int returnGCD(int a,int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // the question is on the easier side 
        // Steps:
        // make the function which will return the gcd of the two numbers.
        // iterate through the linked list and play with the pointer and make new node for adjacent gcd.
        
        // base
        if(head->next==NULL)return head;   // if there is only single number.
        ListNode *finl=head;
        while(head->next){
            int num=returnGCD(head->val,head->next->val);
            // new node banado us GCD ki
            ListNode * temp=new ListNode(num);
            temp->next=head->next;
            head->next=temp;
            head=temp->next;
        }

        //  if we will return the head it will return the last node.so make a copy of it.
        // return head;
        return finl;
        
    }
};
int main(){

return 0;
}