// implementing stack using stack
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};
class myStack{
    Node* head;
    int stacksize;
    public:
    myStack(){
        head=NULL;
        stacksize=0;

    }
    void push(int g){
        Node* temp=new Node();
        temp->val=g;
        temp->next=head;
        head=temp;
        cout<<"The push method has been performed on: "<<g<<endl;
        stacksize++;

    }
    void pop(){
        if(head==NULL){
            cout<<"stack is empty spo cannot pop"<<endl;
        }
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        cout<<"element has been poped";
        stacksize--;

    }
    int top(){
        if(head==NULL){
            cout<<"NO top element in stack"<<endl;
            return -1;
        }
        cout<<"top element is "<<head->val<<endl;
        return head->val;
    }
    int size(){
        cout<<"size of stack is: "<<stacksize;
        return stacksize;
    }

};
int main(){
    myStack s1;
    s1.push(3);
    s1.push(4);
    s1.pop();
    s1.push(8);
    s1.size();

return 0;
}