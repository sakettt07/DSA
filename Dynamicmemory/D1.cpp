#include<bits/stdc++.h>
using namespace std;

int getsum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    // The below written line represents that the memory has been allocated dynamically
    // to allocate dynamically we have used new keyword.
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=getsum(arr,n);
    cout<<" the answer is: "<<ans;

return 0;
}