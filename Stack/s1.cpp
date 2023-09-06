#include<bits/stdc++.h>
using namespace std;
// Implementing stack using class
class Stack{
    public:
    int *arr;
    int top;
     int size;
     Stack(int size){
        this->size-=size;
        arr=new int[size];
        top=-1;
     }
     void push(int element){
        if(size-top >1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
        
     }
     void pop(){
        if(top >=0){
            top--;
        }
        else{
            cout<<"stack underflow";
        }

     }
     int peek(){
        if(top>=0)
        return arr[top];
        else{

        }

     }
     bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
     }

};

int main(){
    // Implementation of stack using STL library.
    // stack<int>st;
    // st.push(2);
    // st.push(3);
    // st.pop();
    // cout<<st.top();
    // cout<<endl;
    // if(st.empty()){
    //     cout<<" the stack is empty"<<endl;;
    // }
    // else{
    //     cout<<"stack is not empty";
    // }
 Stack st(5);
 st.push(22);
 st.push(33);
 st.push(44);
 cout<<st.peek();
return 0;
}