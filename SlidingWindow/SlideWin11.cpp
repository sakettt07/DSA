#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        // to handle the circular array appending the same array 
        vector<int>newArr(2*n);
        for(int i=0;i<2*n;i++){
            newArr[i]=nums[i%n];
        }
        // primarily finding out the total number of ones
        int totalOnes=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                totalOnes++;
            }
        }
        // now we have the total number of ones we know about our window size;
        int currOneCnt=0;
        int maxCnt=0;
        int i=0,j=0;
        while(j<2*n){
            if(newArr[j]==1){
                currOneCnt++;
            }
            // window shrink condition
            if(j-i+1>totalOnes){
                currOneCnt-=newArr[i];
                i++;
            }
            maxCnt=max(maxCnt,currOneCnt);
            j++;
        }
        // swaps
        return totalOnes-maxCnt;
    }
};
int main(){

return 0;
}