// Recursion
// printing counting forwards and backwards
#include <bits/stdc++.h>
using namespace std;

// for printing forwards we can create a vector which will stores the array and then we will reverse it.(using STL library)
void printfor(int n)
{
    if (n == 0)
    {
        return;
    }
    printfor(n - 1); // head recusion
    cout << n << " ";
}
void printback(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    printback(n - 1); // tail recursion
}
int main()
{
    int n;
    cout << " Enter any number: ";
    cin >> n;
    cout << endl;
    cout << "This is for backwards:" << endl;
    printback(n);
    cout << endl;
    cout << "This is for forwards:" << endl;
    printfor(n);

    return 0;
}