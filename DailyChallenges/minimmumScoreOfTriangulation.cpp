#include <bits/stdc++.h>
using namespace std;

int solver(int i, int j, vector<int> &values, vector<vector<int>> &dp)
{
    if (j - i < 2)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        int cost = values[i] * values[j] * values[k] + solver(i, k, values, dp) + solver(k, j, values, dp);
        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}

int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solver(0, n - 1, values, dp);
}