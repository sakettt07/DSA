// Starting of with heaps in this file
#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return ;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void deleteheapval(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return ;
        }
        // last element ko root p dal diya
        arr[1]=arr[size];
        size--;

        // correct position
        int i=1;
        while(i<size){
            int leftind=2*i;
            int rightind=2*i+1;
            if(leftind<size && arr[i]<arr[leftind]){
                swap(arr[i],arr[leftind]);
                i=leftind;
            }
            else if(rightind<size && arr[i]<arr[rightind]){
                swap(arr[i],arr[rightind]);
                i=rightind;
            }
            else{
                return ;
            }
        }
    }
};
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n && arr[largest] <arr[left]){
        largest=left;
    }
    if(right<n && arr[largest] <arr[right]){
        largest=right;
    }
    if(largest !=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteheapval();
    h.print();

    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i++){
        heapify(arr,n,i);
    }
    cout<<"Printing  the array now"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


return 0;
}