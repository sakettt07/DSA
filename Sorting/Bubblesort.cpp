// in this tutorial we are goind to learn bubble sort.
#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for (int j = 0; j <n-i; j++)
        {
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
        }   
    }
    cout<<"the sorting has been done "<<endl;
}
void print(int arr[],int size){
    for (int i = 0; i <size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[5] = {56, 7, 2, 6, 76};
    bubblesort(arr, 5);
    print(arr,5);

return 0;
}