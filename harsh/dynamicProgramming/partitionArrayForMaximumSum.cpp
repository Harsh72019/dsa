#include <bits/stdc++.h>
using namespace std;

int solver(int index, vector<int> &arr, int k, vector<int> &dp)
{
    if (index >= arr.size())
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int ans = 0;
    int maxElementForPartition = INT_MIN;
    int end = min(index + k, (int)arr.size());
    for (int start = index; start < end; start++)
    {
        maxElementForPartition = max(maxElementForPartition, arr[start]);
        int length = start - index + 1;
        int take = (maxElementForPartition * length) + solver(start + 1, arr, k, dp);
        ans = max(ans, take);
    }
    return dp[index] = ans;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return solver(0, arr, k, dp);
}