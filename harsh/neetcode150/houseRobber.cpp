#include <bits/stdc++.h>
using namespace std;

int solver(int index, vector<int> &nums, vector<int> &dp)
{
    if (index >= nums.size())
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int pick = nums[index] + solver(index + 2, nums, dp);
    int notPick = solver(index + 1, nums, dp);

    return dp[index] = max(pick, notPick);
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solver(0, nums, dp);
}