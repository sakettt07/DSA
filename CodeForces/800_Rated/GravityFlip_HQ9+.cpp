// #include <bits/stdc++.h>
// using namespace std;
// // char s;
// int main()
// {
    // while(cin>>s) if(s=='H'||s=='Q'||s=='9') {cout<<"YES";return 0;}
    // cout<<"NO";
#include<bits/stdc++.h>
using namespace std;
 
int main()
{int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++) cin>>a[i];
sort(a,a+n);
for(int i=0;i<n;i++) cout<<a[i]<<" ";
}