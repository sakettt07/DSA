// Looking forward to function overloading and overriding.
// Overriding means that parent and child class both contains the same function with different implementation.
#include<bits/stdc++.h>
using namespace std;

class Parent{
    public:
    void getInfo(){
        cout<<"I am the parent.."<<endl;
    }
     virtual void hello(){
        cout<<"helllo from parent";
    }
};
class Child:public Parent{
    public:
    void getInfo(){
        cout<<"I am the child.."<<endl;
    }
    void hello(){
        cout<<"helllo from child";
    }
};

int main(){
    Parent c1;
    c1.getInfo();

return 0;
}