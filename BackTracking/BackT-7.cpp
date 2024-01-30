// Backtracking question -Non Decreasing subsequences.
#include<bits/stdc++.h>
using namespace std;

// With the help of backtracking khandani template
class Solution {
public:
int n;
void solve(vector<int>& temp,int indx,vector<vector<int>>& finl,vector<int>& nums){
    // the giving condition is that the size must be atleast 2.
    if(temp.size()>1)
        finl.push_back(temp);

    unordered_set<int>mp;   //for the uniqueness of the subsequences.
    for(int i=indx;i<n;i++){
        if((temp.empty()||nums[i]>=temp.back())&& mp.find(nums[i])==mp.end()){
            temp.push_back(nums[i]);
            solve(temp,indx+1,finl,nums);
            temp.pop_back();
            mp.insert(nums[i]);
        }
    }
}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>finl;
        vector<int>temp;
        solve(temp,0,finl,nums);
        return finl;
    }
};

// fair distribution of cookies.
class Solution {
public:
int n;
int result=INT_MAX;
void solve(int idx,vector<int> &children,vector<int>& cookies,int k){
    if(idx>=n){

        // taking out the maximum from the total that we have given to each children
        int unfair=*max_element(begin(children),end(children));
        result=min(result,unfair);    //minimum unfairness
        return;
    }
    int cookie=cookies[idx];  //storing the first cookie which is to be given to the children.
    for(int i=0;i<k;i++){
        children[i]+=cookie;    //giving the cookie to the current child
        solve(idx+1,children,cookies,k);   //passing over the next cookie
        children[i]-=cookie;     //taking the cookie back from the children
    }
}
    int distributeCookies(vector<int>& cookies, int k) {
      n=cookies.size();
      vector<int>children(k,0);    //initilizing the children array from  0 and size to be as the total number of children.
      solve(0,children,cookies,k);
      return result;
    }
};

int main(){

return 0;
}