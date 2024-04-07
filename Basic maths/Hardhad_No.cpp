// It is also an leetcode contest question purely based on basic maths.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum=0;
        int n=x;
        while(x>0){
            sum+=x%10;
            x=x/10;
        }
        if(n%sum==0){
            return sum;
        }
        return -1;
    }
};
int main(){
    

return 0;
}