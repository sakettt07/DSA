// Starting off with my greedy playlist and questions. Assign Cookies And Lemonade change.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Using the greedy method 
        int l=0,r=0;
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
int cnt=0;
        while(r<n&& l<m){
            if(g[r]<=s[l]){
                r=r+1;
            l=l+1;
            cnt++;

            }
            else l=l+1;
        }
        return cnt;
    }
};
class Solution {
public:
// super simple greedy algorithm.
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five){
                    five-=1;
                    ten+=1;
                }
                else{
                    return false;
                }
            }

            else{
                    if(ten && five){
                        ten-=1;
                        five-=1;
                    }
                    else if(five>=3){
                        five-=3;
                        
                    }
                    else{
                        return false;
                    }
                }
        }
        return true;
    }
};
int main(){


return 0;
}