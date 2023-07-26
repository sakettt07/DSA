// in this tutorial we are going to perform selection sort
#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        swap(arr[minindex], arr[i]);
    }
}
void print(int arr[],int size){
    for (int i = 0; i <size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[5] = {56, 7, 2, 6, 76};
    selectionsort(arr, 5);
    print(arr,5);
    return 0;
}
