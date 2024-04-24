#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
 
    int n,sum=0,twin2=0,ans=0;
    cin>>n;
    vector<ll>v,v2;
 
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.emplace_back(x);
        sum+=v[i];
    }
 
    sort(v.begin(),v.end());
    
    while(sum>=twin2){
        twin2+=v[n-1];
        sum-=v[n-1];
        ans++;
        n--;
}
cout<<ans<<endl;
       
    return 0;
}