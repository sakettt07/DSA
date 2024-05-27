#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
	cin>>tc;
	string s,str="codeforces";
	while(tc--){
		cin>>s;
		int c=0;
		for(int i=0;i<10;i++){
			if(s[i]!=str[i])
			c++;
		}
	cout<<c<<endl;
	}
return 0;
}