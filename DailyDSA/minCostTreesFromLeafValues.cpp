#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    vector<vector<int>> mx;

    int solve(int l, int r)
    {

        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = INT_MAX;

        for (int k = l; k < r; k++)
        {

            ans = min(
                ans,
                solve(l, k) +
                    solve(k + 1, r) +
                    mx[l][k] * mx[k + 1][r]);
        }

        return dp[l][r] = ans;
    }

    int mctFromLeafValues(vector<int> &arr)
    {

        int n = arr.size();

        dp.assign(n, vector<int>(n, -1));
        mx.assign(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {

            mx[i][i] = arr[i];

            for (int j = i + 1; j < n; j++)
            {
                mx[i][j] = max(mx[i][j - 1], arr[j]);
            }
        }

        return solve(0, n - 1);
    }
};