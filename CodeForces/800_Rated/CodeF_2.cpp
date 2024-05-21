# include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int mini = min(a,min(b,c));
        int cuts = 0;
        if(a%mini == 0 && b%mini == 0 && c%mini == 0){
        cuts += a/mini - 1;
        cuts += b/mini - 1;
        cuts += c/mini - 1;
        if(cuts <= 3)
           cout<<"YES"<<endl;
        else
           cout<<"NO"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}