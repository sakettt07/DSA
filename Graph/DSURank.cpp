#include<bits/stdc++.h>
using namespace std;
// in this method we will be using the rank of the parent to decide which one will be the parent of the other one

class Solution {
    vector<int>parent;
    vector<int>rank;
    public:
    int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}
    int Union(){
        int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent){
        return ;
    }
    if(rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
    }
    else if(rank[y_parent]>rank[x_parent]){
        parent[x_parent]=y_parent;
    }
    else{
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }
    }
};

int main(){
    Solution s1;
return 0;
}