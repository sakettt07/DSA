// Performing two backtracking questions which are
// Permutaiton 1,Permutation 2
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>>ans;
// set is added for the unique ness of the permutations
set<vector<int>>st;
void permutations(vector<int>& nums,int l,int r){
    if(l==nums.size()&& st.find(nums)==st.end()){
        ans.push_back(nums);
        st.insert(nums);
        return ;
    }
    for(int i=l;i<=r;i++){
        swap(nums[i],nums[l]);
        permutations(nums,l+1,r);
        swap(nums[i],nums[l]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permutations(nums,0,nums.size()-1);
        return ans;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permutations(nums,0,nums.size()-1);
        return ans;
    }
};
int main(){

return 0;
}