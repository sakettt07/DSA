// Dynamic Programming Renowed Q but Solving both with the help of Sliding Window.
// Q1-Best Time to Buy and Sell stocks.
// Q2-Best Time to Buy and Sell stocks ii.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// using the sliding window approach.
    int maxProfit(vector<int>& prices) {
        int i=0,j=1;
        int n=prices.size();
        int maxpro=0;
        while(j<n){
            if(prices[i]<prices[j]){
                maxpro=max(maxpro,prices[j]-prices[i]);
            }
            else{
                i=j;
            }
            j++;
        }
        return maxpro;
    }
};
int main(){

return 0;
}