#include <bits/stdc++.h>
using namespace std;

int solver(vector<vector<int>> &triangle, int row, int col, vector<vector<int>> &dp)
{
    if (row == triangle.size() - 1)
        return triangle[row][col];

    if (dp[row][col] != 1e5)
        return dp[row][col];

    int down = solver(triangle, row + 1, col, dp);
    int downRight = solver(triangle, row + 1, col + 1, dp);

    return dp[row][col] = triangle[row][col] + min(down, downRight);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e5));
    return solver(triangle, 0, 0, dp);
}