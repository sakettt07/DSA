#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalMoney(int n) {
        int mon=1,sum=0,k=1;
        for(int i=1;i<=n;i++){
            sum+=k;
            k++;
            if((i)%7==0){
                k=mon+1;
                mon++;
            }
        }return sum;
    }
};
int main(){

return 0;
}