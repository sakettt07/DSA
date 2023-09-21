// Starting off with the queue data structure
// Introduction - works on the principle of first in first out (FIFO)
#include <bits/stdc++.h>
using namespace std;

// Implementing queue using arrays:

class queue{
    int* arr;
    int qfront;
    int rear;
    int size;
    public:
    queue(){
        size=10001;
        arr=new int[size];
        qfront=0;
        rear=0;

    }
    bool isEmpty(){
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }

    }
    void enqueue(int data){
        if(rear==size){
            cout<<"Queue is full "<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }
    int dequeue(){
        if(qfront==rear){
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }
    int front(){
        if(qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];

        }
    }


};





int main()
{

    // create a queue

    // performing stl operations n queue.
    // queue<int> q;
    // q.push(11);
    // q.push(14);
    // q.push(15);
    // cout << "size of queue is :" << q.size() << endl;
    // q.pop();
    // cout << "size of queue is :" << q.size() << endl;
    // if (q.empty())
    // {
    //     cout << "queue is empty " << endl;
    // }
    // else
    // {
    //     cout << "queue is not empty " << endl;
    // }



    return 0;
}