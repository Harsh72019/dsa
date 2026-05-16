#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solver(vector<int> &nums, int index, vector<vector<int>> &ans, vector<int> &subAns)
    {
        if (index >= nums.size())
        {
            ans.push_back(subAns);
            return;
        }
        solver(nums, index + 1, ans, subAns);
        subAns.push_back(nums[index]);
        solver(nums, index + 1, ans, subAns);
        subAns.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subAns;
        solver(nums, 0, ans, subAns);
        return ans;
    }
};