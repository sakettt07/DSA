
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> out;
        int max=*max_element(candies.begin(),candies.end());
       for(auto i : candies){
           if(i+extraCandies>=max)
           out.push_back(true);
           else 
           out.push_back(false);
       }
        return out;
    }
};
int main(){

return 0;
}