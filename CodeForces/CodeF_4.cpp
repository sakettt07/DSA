#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; //all testcases
    cin >> t;
    string arr[100];   //as given
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    // iterating all the strings
    for(int i=0;i<t;i++){
        string temp="",og;     //for the z type of testcases
        for(int j=0;j<t;j++){
            if(i<arr[j].size())temp+=arr[j][i];
        }
        og=temp;
        //palin wali condition
        reverse(temp.begin(),temp.end());
        if(og==temp)cout<<"Yes"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}