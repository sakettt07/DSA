#include <bits/stdc++.h>
using namespace std;

// the below function will be finding the target element in the array.
bool ispresent(int arr[][3], int target, int n, int m)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}
// printing the sum of the row elements.
void printsum(int arr[][3], int n, int m)
{
    for (int n = 0; n < 3; n++)
    {
        int sum = 0;
        for (int m = 0; m < 3; m++)
        {
            sum += arr[n][m];
        }
        cout << sum << " ";
    }
    cout << endl;
}
// the below function will return us the row which contains the maximum sum.
int largestrowsum(int arr[][3], int n, int m)
{
    int maxi = INT_MIN;
    int index = -1;
    for (int n = 0; n < 3; n++)
    {
        int sum = 0;
        for (int m = 0; m < 3; m++)
        {
            sum += arr[n][m];
        }
        if (sum > maxi)
        {
            maxi = sum;
            index = n;
        }
    }
    cout << "the maximum sum is " << maxi << endl;
    return index;
}
int main()
{
    // if you want to insert the elements in your desired row then
    // int arr[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};

    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    // print
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the element to search" << endl;
    int target;
    cin >> target;

    if (ispresent(arr, target, 3, 3))
    {
        cout << "element is found" << endl;
    }
    else
    {
        cout << "element does not found" << endl;
    }
    printsum(arr, 3, 3);

    return 0;
}