#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc,x,y;
    // cout<<"Enter the number of testcases: ";
    cin>>tc;
    while(tc--){
        cin>>x>>y;
        cout<<min(x,y)<<" "<<max(x,y)<<endl;
    }
return 0;
}