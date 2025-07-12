#include <bits/stdc++.h>
using namespace std;

bool solver(int index, vector<int> &nums, int sum, int target, vector<vector<int>> &dp)
{
    if (sum == target)
        return true;
    if (index >= nums.size() || sum > target)
        return false;
    if (dp[index][sum] != -1)
        return dp[index][sum];
    bool pick = solver(index + 1, nums, sum + nums[index], target, dp);
    bool notPick = solver(index + 1, nums, sum, target, dp);
    return dp[index][sum] = pick || notPick;
}
bool canPartition(vector<int> &nums)
{
    int total = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>((total / 2) + 1, -1));
    if (total % 2 != 0)
        return false;
    return solver(0, nums, 0, total / 2, dp);
}