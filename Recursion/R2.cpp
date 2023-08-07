// Recursion
// Day2
// Power of 2,3,4;
#include<bits/stdc++.h>
using namespace std;
int powertwo(int n){
    if(n==0){
        return 1;
    }
    return 2*powertwo(n-1);
}
int powerthree(int n){
    if(n==0){
        return 1;
    }
    return 3*powerthree(n-1);
}
int powerfour(int n){
    if(n==0){
        return 1;
    }
    return 4*powerfour(n-1);
}
int main(){
    int n;
    cout<<"Enter any number for getting powered: ";
    cin>>n;
    cout<<endl;
    int ans=powertwo(n);
    int ans2=powerthree(n);
    int ans3=powerfour(n);
    cout<<" the answer is: "<<ans<<endl;
    cout<<" the answer is: "<<ans2<<endl;
    cout<<" the answer is: "<<ans3<<endl;

return 0;
}