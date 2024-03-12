// 1171 Remove Zero Sum Consecutive Nodes from Linked List
// its a linked list medium problem 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp=head;
        vector<int>newar;
        // iterating the elements of the LL in the form of vector.
        while(temp){
            newar.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>temparr;
        for(int i=0;i<newar.size();i++){
            if(newar[i]!=0){
                temparr.push_back(newar[i]);
            }
        }
        for(int i=0;i<temparr.size();i++){
            int sum=temparr[i];
            for(int j=i+1;j<temparr.size();j++){
                sum+=temparr[j];
                if(sum==0){
                    temparr.erase(temparr.begin()+i,temparr.begin()+j+1);
                    i--;
                    break;
                }
            }
        }
        // till now humne new temparr m wo elements store kara liye h jo 0 nhi banaenge.

        // converting the vector back to linked list as we have to return the head of the LL.
        if(temparr.size()==0)return NULL;
        ListNode* first=new ListNode(temparr[0]);
        ListNode*x=first;
        for(int i=1;i<temparr.size();i++){
            ListNode* second=new ListNode(temparr[i]);
            x->next=second;
            x=x->next;
        }
        return first;
    }
};
int main(){

return 0;
}