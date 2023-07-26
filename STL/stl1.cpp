// we have learnt about vector;
#include<bits/stdc++.h>
using namespace std;

int main(){
    int basic[3]={1,2,3};

    array  <int,4> a = {1,2,3,4};
    int size=a.size();
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"element at 2nd"<<a.at(2)<<endl;
    cout<<"checking for empty"<<a.empty()<<endl;
    cout<<"checking for front"<<a.front()<<endl;
    cout<<"checking for back"<<a.back()<<endl;
    
return 0;
}