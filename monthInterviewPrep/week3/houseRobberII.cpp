#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int start, int end)
    {
        if (start == end)
            return nums[start];

        vector<int> dp(nums.size(), 0);

        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[end];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(
            solve(nums, 0, n - 2),
            solve(nums, 1, n - 1));
    }
};