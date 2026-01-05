#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int> &nums, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        solve(index + 1, nums, ans);
        swap(nums[i], nums[index]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    solve(0, nums, ans);
    return ans;
}



// Done by me

class Solution {
public:
    void solve(vector<int>& nums, vector<bool>& used,
               vector<int>& path, vector<vector<int>>& ans) {

        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);

            solve(nums, used, path, ans);

            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> path;

        solve(nums, used, path, ans);
        return ans;
    }
};
