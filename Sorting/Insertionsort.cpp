// in this tutorial we are going to learn insertion sort.
#include<bits/stdc++.h>
using namespace std;
void insertionsort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
    

}
void print(int arr[],int size){
    for (int i = 0; i <size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[5] = {56, 7, 2, 6, 76};
    insertionsort(arr, 5);
    print(arr,5);


return 0;
}