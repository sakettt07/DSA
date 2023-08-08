// recursion Day-3
// sorting the array using recursion
#include<bits/stdc++.h>
using namespace std;

bool issorted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
         
    }
    else{
        bool remaining=issorted(arr+1,size-1);
        return remaining;
    }

}
int getSum(int arr[],int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int remain=getSum(arr+1,size-1);
    int sum=arr[0]+remain;
    return sum;
}
int main(){
    int arr[5]={2,4,8,6,7};
    int size=5;
    bool ans=issorted(arr,size);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
        
    }

return 0;
}