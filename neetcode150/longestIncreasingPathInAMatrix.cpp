#include <bits/stdc++.h>
using namespace std;

int solver(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int num = 1;
    int val = matrix[i][j];

    if (j + 1 < matrix[0].size() && matrix[i][j + 1] > val)
        num = max(num, 1 + solver(i, j + 1, matrix, dp));
    if (j - 1 >= 0 && matrix[i][j - 1] > val)
        num = max(num, 1 + solver(i, j - 1, matrix, dp));
    if (i + 1 < matrix.size() && matrix[i + 1][j] > val)
        num = max(num, 1 + solver(i + 1, j, matrix, dp));
    if (i - 1 >= 0 && matrix[i - 1][j] > val)
        num = max(num, 1 + solver(i - 1, j, matrix, dp));

    return dp[i][j] = num;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int result = 0;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            result = max(result, solver(i, j, matrix, dp));
        }
    }
    return result;
}