#include <bits/stdc++.h>
using namespace std;

int solver(int index, int prevIndex, vector<int> &nums, vector<vector<int>> &dp)
{
    if (index == nums.size())
        return 0;

    if (dp[index][prevIndex + 1] != -1)
        return dp[index][prevIndex + 1];

    int notPick = solver(index + 1, prevIndex, nums, dp);
    int pick = 0;

    if (prevIndex == -1 || nums[prevIndex] < nums[index])
        pick = 1 + solver(index + 1, index, nums, dp);

    return dp[index][prevIndex + 1] = max(pick, notPick);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solver(0, -1, nums, dp);
}