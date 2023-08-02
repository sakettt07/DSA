// we are going to learn about the basics of pointer.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 5;
    cout << num << endl;
    cout << "the address of num is " << &num<<endl;;

    // pointer stores the address
    int *ptr=&num;
    cout<<"the value is: "<<*ptr<<endl;
    // the sixe of the pointer is always remians 8 as it stores the address in the hexa deecimal format.
    return 0;
}