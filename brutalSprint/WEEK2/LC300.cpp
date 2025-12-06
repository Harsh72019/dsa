#include <bits/stdc++.h>
using namespace std;

int solver(const vector<int> &nums, int index, int prevIndex, vector<vector<int>> &dp)
{
    if (index == nums.size())
        return 0;
    int &mem = dp[index][prevIndex + 1];
    if (mem != -1)
        return mem;

    int notTake = solver(nums, index + 1, prevIndex, dp);

    int take = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex])
        take = 1 + solver(nums, index + 1, index, dp);

    mem = max(take, notTake);
    return mem;
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solver(nums, 0, -1, dp);
}

int lengthOfLIS(vector<int>& nums) {
        vector<int> tails; 
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return (int)tails.size();
    }