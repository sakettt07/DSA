// Upscalling code forces question.
#include <iostream>
using namespace std;
int main()
{
    int t, n, i, j;
    cin >> t;
    while (t--)
        for (i = 0, cin >> n; i < n * 2; i++, cout << '\n')
            for (j = 0; j < n * 2; j++)
                cout << (j / 2 % 2 != i / 2 % 2 ? '.' : '#');
}