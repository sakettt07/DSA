#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int l = 0, u = 0;
    cin >> s;
    // we are storing the number of upper and lowercase letters if upper greater then convert or vice versa.
    for (char c : s)
        (isupper(c) ? u : l)++;
    for (char c : s)
    // converting on the basis of condition
        cout << char((u > l) ? toupper(c) : tolower(c));
    return 0;
}