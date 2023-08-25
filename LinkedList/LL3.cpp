// to detect the loop inside a linked list
#include<bits/stdc++.h>
using namespace std;

bool detectLoop(Node* head){
    if(head==NULL){
        return false;
    }
    map<Node* ,bool>visited;
    Node* temp=head;
    while(temp !=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

// Doing the Floyds cycle detection method
Node* floydLoop(Node* head){
    if(head==NULL){
        return false;
    }
    Node* slow=head;
    Node* fast=head;
    while(slow !=NULL && fast !=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return 1;
        }
    }
    return false;
}

int main(){

return 0;
}