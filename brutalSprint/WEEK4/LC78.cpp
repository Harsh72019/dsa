#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int index)
{
    if (index == nums.size())
    {
        ans.push_back(curr);
        return;
    }
    solve(ans, curr, nums, index + 1);
    curr.push_back(nums[index]);
    solve(ans, curr, nums, index + 1);
    curr.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> curr;
    solve(ans, curr, nums, 0);
    return ans;
}