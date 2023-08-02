// in this we will learn about the arrays relation with pointer.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10]={3,4,5};


    cout<<"address of first memory block is: "<<arr<<endl;
    // the above statement will give the address of the first memory block
    cout<<"address of first memory block is: "<<&arr[0]<<endl;
    // the above sttemenet will print the same address

    // having fun with them
    cout<<"4th"<<*arr<<endl;      //print the first value
    cout<<"5th"<<*arr+1<<endl;    // add 1 to the fetched value
    cout<<"6th"<<*(arr+1)<<endl;  // this print the 2nd value which is 5
    cout<<"7th"<<*(arr)+1<<endl;  // add 1 to the fetched value
return 0;
}