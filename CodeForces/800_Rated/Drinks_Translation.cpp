#include<bits/stdc++.h>
using namespace std;

int main(){
    // string a,b;
    // cin>>a>>b;
    // reverse(a.begin(),a.end());
    // if(a==b)cout<<"YES";
    // else cout<<"NO";
//     int n;
//  cin>>n;
//  cout<<(n+4)/5;
int n,x=0,a;
cin>>n;
for (int i = 0; i < n; i++)
{
    cin>>a;
    x=x+a;
}

cout<<(double)x/n;
return 0;
}