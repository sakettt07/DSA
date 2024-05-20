// Codeforces -Watermelon and the Word Capitalization 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<((n%2==0 && n>2) ? "YES":"NO");
    string n;
    cin>>n;
    n[0]=toupper(n[0]);
    cout<<n;
return 0;
}