#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long minimumHealth(vector<int>& damage,int armor){
        long long int totalDmg=0;
        int maxDmg=INT_MIN;

        for(int d:damage){
            totalDmg+=d;
            maxDmg=max(maxDmg,d);
        }
        int savedHealth=min(maxDmg,armor);
        return totalDmg-savedHealth+1;

    }
};
int main(){

return 0;
}