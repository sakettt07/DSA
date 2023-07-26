// Day2 swap alternate elements in an array
#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }cout<<endl;
    
}
void alternate(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        /* code */
        if(i+1 < size){
            swap(arr[i],arr[i+1]);
        }
    }
    
}
int main(){
    int even[6]={1,2,3,5,4,2};
    int odd[5]={2,3,5,4,2};
    alternate(odd,5);
    printarray(odd,5);

return 0;
}