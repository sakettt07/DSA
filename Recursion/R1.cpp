// Day-1
// #Factorial
// #Fibonacci
#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1; 
    }
    return n*factorial(n-1);
}
int fibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int ans=fibo(n-1)+fibo(n-2);
    return ans;
}
int main(){
    int n;
    cout<<"Enter any number: ";
    cin>>n;
    cout<<endl;
    int ans=factorial(n);
    int ans2=fibo(n);
    cout<<"the factorial of the entered number is "<<ans <<endl;
    cout<<"the fibonacci of the entered number is "<<ans2<<endl;

return 0;
}