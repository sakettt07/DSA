#include<bits/stdc++.h>
using namespace std;

class A{
    void method1(){
        cout<<"Method 2 called"<<endl;
    }
};
class B{
    A* a;
    B(){
        a=new A();
    }
    void method2(){
        cout<<"Method 2 called"<<endl;
    }
};
int main(){
    B * b=new B();
    b->method2();
    b->a->method1();

return 0;
}