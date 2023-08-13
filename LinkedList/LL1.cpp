// This is my first linked list lecture ------------->>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

// Insertion in the linkedlist Singlyy
void insertathead(Node* &head,int d){ //here the reference has been taken so that there must not be a copy which makes extra space
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}
void print(Node* &head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    // created a new node
    Node* node1=new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    Node* head=node1;
    print(head);

    insertathead(head,12);
    print(head);
    insertathead(head,15);
    print(head);

return 0;
}