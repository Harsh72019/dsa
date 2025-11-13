#include <bits/stdc++.h>
using namespace std;
// Brute Force
class Solution
{
public:
    int solve(int index, vector<int> &nums)
    {
        if (index >= nums.size())
            return 0;
        int take = nums[index] + solve(index + 2, nums);
        int notTake = 0 + solve(index + 1, nums);
        return max(take, notTake);
    }
    int rob(vector<int> &nums)
    {
        return solve(0, nums);
    }
};

// DP approach
class Solution
{
public:
    int solve(int index, vector<int> &nums, vector<int> &dp)
    {
        if (index >= nums.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int take = nums[index] + solve(index + 2, nums, dp);
        int notTake = 0 + solve(index + 1, nums, dp);
        return dp[index] = max(take, notTake);
    }
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};

//TAbulated approach
class Solution
{   
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};