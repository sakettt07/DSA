// strings1
// legth of the string.
// reverse the string.
// checkpalindrome.
#include<bits/stdc++.h>
using namespace std;

char toLowercase(char ch){
    if(ch>='a'&& ch<='z')
    return ch;
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
}
bool checkpalin(char a[],int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        if(a[s]!=a[e])
        return 0;
        else{
            s++;
            e--;
        }
    }
    return 1;
}
int getlength(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}
void reverse(char name[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(name[s++],name[e--]);
    }

}
int main(){
    char name[20];
    cout<<"enter your name"<<endl;
    cin>> name;
    cout<<"your name is"<<endl;
    cout<<name<<endl;
    // name[2]='\0';
    // cout<<"length is : "<<getlength(name)<<endl;
    int length=getlength(name);
    reverse(name,length);
    cout<<" the reverse of your entered string is "<<endl;
    cout<<name;

    cout<<"palidrome or not:"<<checkpalin(name,length)<<endl;


// functions-->
// getline()--->
// strlen()--->
// compare()--->
// strcpy()--->

return 0;
}