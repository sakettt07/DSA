// Implementing circular queue->

/* Theory - It is an extension of queue in which when we perform operations like push pop then we move to n so if we have the blank spaces remaining at the starting then our rear will move to the empty part so that the space will not be left used.*/

#include <bits/stdc++.h>
using namespace std;
class circularQ
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    circularQ(int n)
    {
        size = 10001;
        arr = new int[size];
        front = rear = -1;
    }
    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full";
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = value;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
    }
    int dequeue()
    {
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
};
    int main()
    {

        return 0;
    }