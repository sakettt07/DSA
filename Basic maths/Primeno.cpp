// questions to be done---->
// Q1-Pigeonhole Principle.
// Q2-Catalan Number.

#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;

}
// seive of eratosthenes.
int countprime(int n){
    int cnt=0;
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=false;
    for(int i=2;i<n;i++){
        if(prime[i]){
            cnt++;
            for(int j=2*i;j<n;j++){
                prime[j]=0;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    if(isprime(n)){
        cout<<"The number is Prime"<<endl;
    }
    else{
        cout<<"The number is not Prime"<<endl;
    }

return 0;
}