// stoi is an important stl keyword which help in the conversion of string into the integer.
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "123";
    int intValue = stoi(str);

    cout << "String value: " << str << endl;
    cout << "Integer value: " << intValue << endl;
return 0;
}