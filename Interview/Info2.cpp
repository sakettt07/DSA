#include<bits/stdc++.h>
using namespace std;


const int MOD=10000;
void countArry(int N,int K,int curr,int pre,vector<int> &arrry,int &cnt){
    // base case to stop at
    if(curr==K){
        cnt=(cnt+1)%MOD;
        return;
    }
    // starting from one is because we have to chekc for the divisibility condition.
    for(int i=1;i<=N;i++){
        if(pre==0 || i%pre==0){
            // condition mili array m push
            arrry[curr]=i;
            // call recursion
            countArry(N,K,curr+1,i,arrry,cnt);
            cout<<arrry[curr];
        }
    }
}

int main(){
    int N; 
    cout<<"Enter the number you want to perform actions on :";
    cin>>N;
    cout<<endl;
    int K;
    cout<<"Enter the size of the array you want"<<endl;
    cin>>K;
    cout<<endl;

    int cnt=0;
    vector<int>arrry(K);
    // function call hoga
    countArry(N,K,0,0,arrry,cnt);

    cout<<"total number of possible arrays"<<cnt<<endl;
    return 0;
}