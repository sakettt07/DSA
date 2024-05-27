#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    set<char> st;  //for storing the unique characters.
    char c;
    cin >> n;
    while (cin >> c)
        st.insert(tolower(c));
    cout << (st.size() == 26 ? "YES" : "NO"); //if stack is of 26 alphabets size

    return 0;
}