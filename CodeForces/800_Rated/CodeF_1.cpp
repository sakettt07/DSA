#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,l1,l2;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>l1>>l2>>s1>>s2;
		int a=-1;
		for(int i=0;i<=10;i++){
			if(s1.find(s2)!=-1){
				a=i; break;
			}
			s1+=s1;
		}
		cout<<a<<endl;
	}
}