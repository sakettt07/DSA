// this file is for subsets question:
// I have only written the code it will not run on the ide it will run on the questions page on leetcode.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //.this is my iterative approach. 

    // vector<vector<int>> subsets(vector<int> & nums)
    // {
    //     vector<vector<int>> ans;
    //     vector<int> v;
    //     ans.push_back(v);
    //     if (nums.size() == 0)
    //     {
    //         return ans;
    //     }
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         vector<vector<int>> v;
    //         v = ans;
    //         int x = nums[i];
    //         for (int j = 0; j < v.size(); j++)
    //         {
    //             v[j].push_back(x);
    //         }
    //         for (int k = 0; k < ans.size(); k++)
    //         {
    //             v.push_back(ans[k]);
    //         }
    //         ans = v;
    //     }
    //     return ans;
    // }




    // Recursive approach


    // void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>&ans){
    //     if(index>=nums.size()){
    //         ans.push_back(output);
    //         return ;
    //     }

    //     // exclude
    //     solve(nums,output,index+1,ans)
    //     // include
    //     int element=nums[index];
    //     output.push_back(element);
    //     solve(nums,output,index+1,ans);
    // }
}