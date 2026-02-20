#include <bits/stdc++.h>
using namespace std;

int solver(vector<vector<int>> &grid, int r, int c1, int c2, vector<vector<vector<int>>> &dp)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (r >= rows || c1 < 0 || c1 >= cols || c2 < 0 || c2 >= cols)
        return -1e8;
    if (dp[r][c1][c2] != -1)
        return dp[r][c1][c2];
    int cherries = (c1 == c2)
                       ? grid[r][c1]
                       : grid[r][c1] + grid[r][c2];

    if (r == rows - 1)
        return cherries;

    int ans = -1e8;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int nC1 = c1 + i;
            int nC2 = c2 + j;
            ans = max(ans,
                      solver(grid, r + 1, nC1, nC2, dp));
        }
    }

    return dp[r][c1][c2] = cherries + ans;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int cols = grid[0].size();
    int rows = grid.size();
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
    return solver(grid, 0, 0, cols - 1, dp);
}