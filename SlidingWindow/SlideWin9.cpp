// another LC potd
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarrcnt(vector<int> &nums, int k){
        int l = 0, r = 0, count = 0;
        unordered_map<int, int> mp;
        cout<<"The count iteration is: ";
        while(r < nums.size()){
            mp[nums[r]]++;

            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) 
                    mp.erase(nums[l]);
                l++;
            }
            
            count += r - l + 1;
            r++;
            cout<<endl;
            cout<<count<<" ";
        }
        
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrcnt(nums, k) - subarrcnt(nums, k-1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    
    int result = sol.subarraysWithKDistinct(nums, k);
    cout<<endl;
    cout << "Number of good subarrays: " << result << endl;

    return 0;
}
