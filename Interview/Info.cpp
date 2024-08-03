#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ex;
    cout<<"Enter the number of monster and the initial expreince as mentioned in the question.";
    cin>>n>>ex;
    vector<int>power(n);
    vector<int>bonus(n);
    // taking the input for powers and the bonus
    for(int i=0;i<n;i++){
        cin>>power[i];
        
    }
    for(int i=0;i<n;i++){
        cin>>bonus[i];
    }
    // pair banado dono ka

    vector<pair<int,int>>monsters(n);
    for(int i=0;i<n;i++){
        monsters[i]={power[i],bonus[i]};
    }
    sort(monsters.begin(),monsters.end());
    int defCnt=0;
    for(const auto& it:monsters){
        if(ex>=it.first){
            ex+=it.second;
            defCnt++;
        }
        else{
            break;
        }
    }
    cout<<defCnt<<endl;
return 0;
}