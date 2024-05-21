#include<bits/stdc++.h>
using namespace std;
long long k,l,r,x,y;
int main()
{
	cin>>l>>r>>x>>y>>k;
    // iterating over the all possible expereinces
	for(;x<=y;x++)
	{
		if(l<=x*k&&x*k<=r)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}