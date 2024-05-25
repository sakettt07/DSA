#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, flag = 0;
        cin >> n;
        // inserting the elements in the array.
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        // condition for the absolute difference.
        for (i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] > 1)
            {
                flag = 1;
                cout << "NO\n";
                break;
            }
        }
        if (flag == 0)
        {
            cout << "YES\n";
        }
    }
}