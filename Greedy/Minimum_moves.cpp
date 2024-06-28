// this problem is minimum  moves to reach target 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// solving the problem in the opposite manner
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        while(target>1){
            if(maxDoubles){
                if(target%2)ans+=2;
                else{
                   ans++; 
                }
                target/=2;
                maxDoubles--;
            }
            else {
                ans+=target-1; 
                break;
            }
        }
        return ans;
    }
};
int main(){

return 0;
}