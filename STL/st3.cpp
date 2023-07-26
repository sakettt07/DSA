// in this file we are going to look at waht is deque
// ,list,stack,queue.
#include<bits/stdc++.h>
using namespace std;

int main(){

    deque<int>d;
    d.push_back(3);
    d.push_front(4);
    for(int i:d){
        cout<<i<<" ";
    }

    list<int> n{5,100};
    for(int i:n){
        cout<<i<<" ";
    }
    stack<int>s;
    s.push(2);
    s.push(23);
    s.push(5);
    s.pop();
    s.pop();
    s.top();
    s.empty();
    queue<int>q;
    q.push(3);
    q.push(2);
    q.push(9);



return 0;
}