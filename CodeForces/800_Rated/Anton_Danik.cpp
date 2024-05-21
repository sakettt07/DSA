#include<bits/stdc++.h>
using namespace std;

int main(){
    // int n;
    // cin>>n;
    // string ab;
    // cin>>ab;
    // int Acnt=0,Dcnt=0;
    // for(int i=0;i<ab.length();i++){
    //     if(ab[i]=='A'){
    //         Acnt++;
    //     }
    //     else if(ab[i]=='D'){
    //         Dcnt++;
    //     }
    // }
    // // cout<<Acnt<<"=:="<<Dcnt;
    // if(Acnt>Dcnt) cout<<"Anton";
    // else if(Acnt<Dcnt) cout<<"Danik";
    // else cout<<"Friendship";


    // the above code is working perfectly for all the testcases given and the the edge cases but its CF platform of not accepting it.

    int n,Acnt=0,Dcnt=0;
    cin>>n;
    char c;
    for(int i=0; i<n; i++)cin>>c,(c=='A')?Acnt++:Dcnt++;
    (Acnt>Dcnt)?cout<<"Anton":((Acnt<Dcnt)?cout<<"Danik":cout<<"Friendship");
return 0;
}