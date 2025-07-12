#include <bits/stdc++.h>
using namespace std;

int solver(int row, int col1, int col2, vector<vector<int>> &g, vector<vector<vector<int>>> &dp)
{
    int n = g.size();
    int m = g[0].size();

    if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
        return -1e8;

    if (row == n - 1)
    {
        if (col1 == col2)
            return g[row][col1];
        else
            return g[row][col1] + g[row][col2];
    }

    if (dp[row][col1][col2] != -1)
        return dp[row][col1][col2];

    int ans = (col1 == col2) ? g[row][col1] : g[row][col1] + g[row][col2];
    int maxNext = INT_MIN;

    for (int d1 = -1; d1 <= 1; d1++)
    {
        for (int d2 = -1; d2 <= 1; d2++)
        {
            int next = solver(row + 1, col1 + d1, col2 + d2, g, dp);
            maxNext = max(maxNext, next);
        }
    }

    ans += maxNext;
    return dp[row][col1][col2] = ans;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solver(0, 0, m - 1, grid, dp);
}