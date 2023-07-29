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