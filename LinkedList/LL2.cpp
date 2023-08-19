// will be learning doubly linked list in this tutorial
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};

void print(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next; 
    }
    cout<<endl;
}

int getlength(Node* head){
    int len=0;
    Node* temp=head;
    while(temp != NULL){
        len++;
        temp=temp->next; 
    }
    return len;
}
void insertAtHead(Node* &head,int d ){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;

    }
    else{
        Node* temp=new Node(d);
    temp->next=head;
    head->prev= temp->next;
    head=temp;
    }
}
void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    
}
void insertAtPosi(Node* & tail,Node* & head,int position,int d){
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    // cout<<getlength(head)<<endl;

    insertAtHead(head,11);
    print(head);
    insertAtHead(head,12);
    print(head);
    insertAtHead(head,13);
    print(head);

    insertAtTail(tail,15);
    print(head);
    insertAtPosi(tail,head,3,24);
    print(head);

return 0;
}