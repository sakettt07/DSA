#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        n++;
        string ns = to_string(n);
        set<char> us(begin(ns), end(ns));
        // for my personal  understanding
        // for (char it :us)
        // {
        //     cout<<it<<" ";
        // }
        
        if (us.size() == ns.size())
            break;
    }
    // cout<<endl;
    // cout<<"The final distinct digit year is"<<endl;
    cout << n;
}