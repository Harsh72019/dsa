#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return {};

    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1), parent(n, -1);
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex])
        {
            maxIndex = i;
        }
    }

    vector<int> result;
    for (int i = maxIndex; i >= 0; i = parent[i])
    {
        result.push_back(nums[i]);
        if (parent[i] == -1)
            break;
    }

    reverse(result.begin(), result.end());
    return result;
}
