// in this we i have studied about doubley ended queue
#include<bits/stdc++.h>
using namespace std;

int main(){
    // using stl
    deque<int>d;
    d.push_front(12);
    d.push_back(10);
    // Agr koi front se dekhega toh ise yeh dikhega
    cout<<d.front()<<endl;
    // Agr koi rear se dekhega toh ise yeh dikhega
    cout<<d.back()<<endl;
    d.pop_front();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;


return 0;
}