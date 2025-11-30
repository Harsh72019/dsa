#include <bits/stdc++.h>
using namespace std;

int solver(const vector<int> &nums, int index, bool takeLast, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (index >= n)
        return 0;

    int flag = takeLast ? 1 : 0;
    if (dp[index][flag] != -1)
        return dp[index][flag];

    int toTake = nums[index];
    if (index == n - 1 && takeLast)
        toTake = 0;

    int take = toTake + solver(nums, index + 2, takeLast, dp);
    int notTake = solver(nums, index + 1, takeLast, dp);

    return dp[index][flag] = max(take, notTake);
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    vector<vector<int>> dp(n, vector<int>(2, -1));

    int takeFirst = nums[0] + solver(nums, 2, true, dp);
    int notTakeFirst = solver(nums, 1, false, dp);

    return max(takeFirst, notTakeFirst);
}
