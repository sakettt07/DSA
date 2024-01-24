// i will be studying about the use of substr which i havent much
#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string>st;
    st.insert("apple");
    st.insert("banana");
    st.insert("grape");
    st.insert("orange");

    cout<<"Watching all the contents of the set"<<endl;
    for(const string& dis:st){
        cout<<dis<<" ";
    }

    // Now printing all the substring of the string inside the set
cout<<endl;
    cout<<"************************************************"<<endl;
    for(const string& dis:st){
        cout<<"word :"<<dis<<" "<<"substring is:"<<endl;
        for(int i=0;i<dis.length();i++){
            cout<<dis.substr(0,i+1)<<" "<<endl;
        }
    }
return 0;
}