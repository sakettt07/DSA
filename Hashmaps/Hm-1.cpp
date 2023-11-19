// In this file we are going to start with a new data structure which is hashmap
// this data structure is the mostly use data structures because the Time complexity it provides to the user.
// The time complexity this data structures uses is O(1).
#include<bits/stdc++.h>
using namespace std;

int main(){

    // creation
    unordered_map<string,int>m;

    // Insertion in the map;
    pair<string,int>p=make_pair("babbar",3);
    m.insert(p);

    pair<string,int>pair2("love",2);
    m.insert(pair2);

    m["mera"]=1;
    // the above line will be added as a key value pair in the map

    m["mera"]=2;
    // the above line will not be added because a map always take the unique value so it will update the count of the key.

    // Searching
    cout<<"Everything is running fine"<<endl;


return 0;
}