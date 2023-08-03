// in this we are going to learn about double pointer (not so an important topic);
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 20;
    int *p = &i;
    int **p2 = &p;
    cout<<"running good"<<endl;
    cout<<"printing p: "<<p<<endl;
    cout<<" address of p: "<<&p<<endl;
    cout<<*p2<<endl;

    cout<<"printing i: "<<i<<endl;
    cout<<"printing i: "<<*p<<endl;
    cout<<"printing i: "<<**p2<<endl;

    return 0;
}