#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string arr[100];
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    for(int i=0;i<t;i++){
        string temp="",og;
        for(int j=0;j<t;j++){
            if(i<arr[j].size())temp+=arr[j][i];
        }
        og=temp;
        reverse(temp.begin(),temp.end());
        if(og==temp)cout<<"Yes"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}