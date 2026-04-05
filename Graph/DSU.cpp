// Disjoint set union new graph topic
// Disjoint sets are those when the intersection is taken it comes out to be phi or NULL we can say in codingg terms.
// Done with the theory part
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int>rank;
vector<int>parent;
int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        //DSU method 
        if(connections.size()<n-1){
            return -1;
        }
        for(int i=0;i<n;i++){
            parent[i]=i;
        }


    }
};
int main(){

return 0;
}