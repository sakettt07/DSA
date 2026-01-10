#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0){
            return 0;
        }
        vector<long long>F(31,0);  // a number can have 32 bits only
        F[0]=1;
        //storing all the ith bit set
        for(int i=1;i<=30;i++){
            F[i]=2*F[i-1]+1;
        }
        int result=0;
        int sign=1;
        for(int i=30;i>=0;i--){
            int ithBit=((1<<i)&n);
            if(ithBit==0){
                continue;
            }
            if(sign>0){
                result+=F[i];
            }
            else{
                result-=F[i];
            }
            sign=sign*(-1);
        }
        return result;
    }
};
int main(){

return 0;
}