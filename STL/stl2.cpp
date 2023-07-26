// in this we will learn about vector;
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v;
    cout<<"capacity->"<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"capacity->"<<v.capacity()<<endl;
    cout<<"capacity->"<<v.size ()<<endl;
 
    v.pop_back();
    for(int i:v){
        cout<<i<<" ";
    }

return 0;
}