// In this file questions on stack has been solved
// reverse a string using stack
// delete the middle element of the stack
// Valid parentheses
// Insert an element at the bottom of the stack
// Reverse stack using recursion
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="saket";
    stack<char>st;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        st.push(ch);
    }
    string temp="";
    while(!st.empty()){
        char ch=st.top();
        temp.push_back(ch);
        st.pop();
    }
    cout<<"answer is :"<<temp<<endl;


return 0;
}