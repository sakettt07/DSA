// In this i have done Rating Increase.
// Description is simple we have to iterate and make two strings if exist.

#include<bits/stdc++.h>
using namespace std;
// #define int long long
 
void solve(){
	string s;     //the big string
	cin>>s;
	for(int i=1;i<s.length();i++){
		string a=s.substr(0,i);   //splitting the string into 2
		string b=s.substr(i);
        // if new string begins with the 0 not accepted
		if(s[i]!='0' && stoi(b)>stoi(a)){
			cout<<a<<" "<<b<<endl;
			return;
		}
	}
	cout<<-1<<endl;
 
}
 
int32_t main(){
	int t;        //total number of testcases.
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
 