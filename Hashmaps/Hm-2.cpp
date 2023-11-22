// Some questions on Hashmaps.
// Two Sum
// Valid Anagram
// Contains Duplicate
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> list;
        for (int i = 0; i < nums.size(); i++)
        {
            if (list.find(target - nums[i]) != list.end())
            {
                ans.push_back(list[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            list[nums[i]] = i;
        }
        return ans;
    }
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]])
            {
                return true;
            }
            m[nums[i]]++;
        }
        return false;
    }
    bool isAnagram(string s, string t)
    {
        vector<int> mp(26, 0);
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (mp[i] != 0)
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}