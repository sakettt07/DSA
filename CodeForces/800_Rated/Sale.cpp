#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int v[n];
    int ans=0;

    // getting the array of integers.
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v,v+n);
    for(int i=0;i<m;i++){
        if(v[i]>=0)break;
        ans+=v[i];
    }
   cout<< abs(ans);


return 0;
}