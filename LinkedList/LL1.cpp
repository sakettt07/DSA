// This is my first linked list lecture ------------->>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
    }
};

// Insertion in the linkedlist Singlyy
void insertathead(Node* &head, int d)
{ // here the reference has been taken so that there must not be a copy which makes extra space
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertattail(Node* &tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void innsertatmid(Node *&tail,Node *&head, int position, int d)
{
    if(position==1){
        insertathead(head,d);
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
        insertattail(tail,d);
        return;
    }
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void deletenode(int position,Node *&head){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;

        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}

int main()
{
    // created a new node
    Node *node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertattail(tail, 12);
    print(head);

    insertattail(tail, 15);
    print(head);
    innsertatmid(tail,head, 4, 22);
    print(head);

    deletenode(1,head);
    print(head);

    return 0;
}