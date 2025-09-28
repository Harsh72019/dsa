#include <bits/stdc++.h>
using namespace std;

int solver(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (row == triangle.size() - 1)
        return triangle[row][col];
    if (row >= triangle.size() || col >= triangle[row].size())
        return 1e9;
    if (dp[row][col] != -1)
        return dp[row][col];

    int down = solver(row + 1, col, triangle, dp) + triangle[row][col];
    int downRight = solver(row + 1, col + 1, triangle, dp) + triangle[row][col];

    return dp[row][col] = min(down, downRight);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int rows = triangle.size();
    vector<vector<int>> dp(rows);
    for (int i = 0; i < triangle.size(); i++)
    {
        dp[i] = vector<int>(triangle[i].size(), -1);
    }
    return solver(0, 0, triangle, dp);
}
