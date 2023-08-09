// Recusiorn normal questions on strings
#include<bits/stdc++.h>
using namespace std;


void reverse(string& str,int i,int j){
    if(i>j){
        return ;
    }
    swap(str[i],str[j]);
    i++;
    j--;
    reverse(str,i,j);
}
bool isPalin(string& str,int i,int j){
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        return isPalin(str,i+1,j-1);
    }
}
int main(){
    string name="naman";
    // reverse(name,0,name.length()-1);
    bool ispalin=isPalin(name,0,name.length()-1);
    if(ispalin){
        cout<<" It is a palindrome"<<endl;
    }
    else{
        cout<<"Its not a palindrome string"<<endl;
    }
    // cout<<name;

return 0;
}