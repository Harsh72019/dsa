#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countSubsets(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

    if (dp[index][target] != -1)
        return dp[index][target];

    int notPick = countSubsets(index - 1, target, arr, dp);
    int pick = 0;
    if (arr[index] <= target)
        pick = countSubsets(index - 1, target - arr[index], arr, dp);

    return dp[index][target] = (pick + notPick) % MOD;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if ((totalSum + d) % 2 != 0 || totalSum < d)
        return 0;

    int target = (totalSum + d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return countSubsets(n - 1, target, arr, dp);
} 