#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;       //total number of testcases
    cin>>t;
    while(t--){
        int n;
        string a,b,c;         //three stringss.
        cin>>n>>a>>b>>c;
        bool acha=false;
        for(int i=0;i<n;i++){
            if(a[i]!=c[i] && b[i]!=c[i]){
                acha=true;
                break;
            }
        }
        cout<<(acha ?"YES":"NO")<<endl;
    }
return 0;
}