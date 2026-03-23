#include <bits/stdc++.h>
using namespace std;

long long solver(vector<int> &nums, vector<int> &colors, int index, int prevTaken, vector<vector<long long>> &dp)
{
    if (index >= nums.size())
        return 0;

    if (dp[index][prevTaken] != -1)
        return dp[index][prevTaken];

    long long notPick = solver(nums, colors, index + 1, 0, dp);

    long long pick = 0;
    if (prevTaken == 0 || colors[index] != colors[index - 1])
    {
        pick = nums[index] + solver(nums, colors, index + 1, 1, dp);
    }

    return dp[index][prevTaken] = max(pick, notPick);
}

long long rob(vector<int> &nums, vector<int> &colors)
{
    int n = nums.size();
    vector<vector<long long>> dp(n, vector<long long>(2, -1));
    return solver(nums, colors, 0, 0, dp);
}