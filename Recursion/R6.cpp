// Linear search using recursion.
// Binary search using recursion.
#include<bits/stdc++.h>
using namespace std;

// bool linear(int arr[],int size,int k){
//     // base case
//     if(size==0)
//         return false;
//     if(arr[0]==k){
//         return true;
//     }
//     else{
//         bool remain=linear(arr+1,size-1,k);
//     }
// }
bool binary(int arr[],int s,int e,int k){
    

    if(s>e){
        return false;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==k){
        return true;
    }
    if(arr[mid]<k){
        return binary(arr,mid+1,e,k);
    }
    else{
        return binary(arr,s,mid-1,k);
    }
}
int main(){
    int arr[5]={3,4,5,5,6};
    int size=5;
    int key=1;
    // bool ans=linear(arr,size,key);
    bool ans=binary(arr,0,4,key);
    if(ans){
        cout<<"The key is present in the array"<<endl;
    }
    else{
        cout<<"The key is not present in the array"<<endl;
    }

return 0;
}