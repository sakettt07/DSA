// binary search mastery
// Question Find the first and the last occurence of the key.
// Question2 Peak index in Mountain array.
#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int size, int key){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int main(){
    int even[6]={2,4,6,8,12,18};
    int odd[5]={3,8,11,14,16};
    int index=binarysearch(even,6,12);
    int index2=binarysearch(odd,5,3);
    cout<<"index of 12 is  "<<index<<endl;
    cout<<"index of 3 is  "<<index2<<endl;
    


return 0;
}