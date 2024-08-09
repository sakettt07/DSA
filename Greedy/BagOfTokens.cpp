// greedy practice question
// Same question can be of Boats to save people
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // we are given with the token array and the power to use the tokens
    int bagOfTokensScore(vector<int> &tokens,int power){
        int cnt=0,maxScore=0;
        int n=tokens.size();
        int l=0,r=n-1;
        while(l<=r){
            if(tokens[l]<=power){
                cnt++;
                power-=tokens[l++];
                maxScore=max(maxScore,cnt);
            }
            else if(cnt>0){   //this means that we have atleast one score
            power+=tokens[r--];
            cnt--;
            }
            else{
                break;
            }
        }
        return maxScore;
    }
};
int main(){

return 0;
}