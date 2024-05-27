#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
	cin>>t;
	while(t>0){
		int n,m;
		cin>>n>>m;
		
		if(m<=n &&(n%2==m%2)){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
		t--;
	}
return 0;
}