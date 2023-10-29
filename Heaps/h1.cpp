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
    if(left<=n && arr[largest] <arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest] <arr[right]){
        largest=right;
    }
    if(largest !=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        // swap kardo pahle or last element ko
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
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
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"Printing  the array now"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    // heapsort wala function
    heapSort(arr,n);
        cout<<"Printing sorted array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    // stlll methodd
    cout<<"Using the priority queue"<<endl;
    priority_queue<int>pq;
    pq.push(4);
    pq.push(2);
    pq.push(6);
    pq.push(3);
    cout<<"element at the top"<<pq.top()<<endl;
    pq.pop();
    cout<<"element at the top"<<pq.top()<<endl;
    cout<<"the size of the priority queue is"<<pq.size()<<endl;

    // for min heap
    priority_queue<int,vector<int>,greater<int>>minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(6);
    minheap.push(3);
    cout<<"element at the top"<<minheap.top()<<endl;
    minheap.pop();
    cout<<"element at the top"<<minheap.top()<<endl;
    cout<<"the size of the priority queue is"<<minheap.size()<<endl;


return 0;
}