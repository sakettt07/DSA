// Say digits in this we write the number and get there string format.
#include<bits/stdc++.h>
using namespace std;
void sayDigit(int n,string arr[]){
    if(n==0){
        return ;
    }
    int digit=n%10;
    n=n/10;
    sayDigit(n,arr);
    cout<<arr[digit]<<" ";
}

int main(){
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cout<<"Enter any number: ";
    cin>>n;
    cout<<endl;
    sayDigit(n,arr);
    cout<<endl;


return 0;
}