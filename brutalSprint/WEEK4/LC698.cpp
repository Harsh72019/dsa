#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> &nums, vector<bool> &used,
         int start, int k, int currentSum, int target)
{

    if (k == 1)
        return true;

    if (currentSum == target)
        return dfs(nums, used, 0, k - 1, 0, target);

    for (int i = start; i < nums.size(); i++)
    {
        if (used[i])
            continue;
        if (currentSum + nums[i] > target)
            continue;

        used[i] = true;
        if (dfs(nums, used, i + 1, k, currentSum + nums[i], target))
            return true;
        used[i] = false;

        if (currentSum == 0)
            return false;
    }
    return false;
}

bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0)
        return false;

    int target = sum / k;
    sort(nums.rbegin(), nums.rend());

    if (nums[0] > target)
        return false;

    vector<bool> used(nums.size(), false);
    return dfs(nums, used, 0, k, 0, target);
}