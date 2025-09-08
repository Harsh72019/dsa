#include <bits/stdc++.h>
using namespace std;

int solver(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
{
    if (i == word1.size())
        return word2.size() - j;
    if (j == word2.size())
        return word1.size() - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (word1[i] == word2[j])
    {
        return dp[i][j] = solver(i + 1, j + 1, word1, word2, dp);
    }

    int insertOp = 1 + solver(i, j + 1, word1, word2, dp);
    int deleteOp = 1 + solver(i + 1, j, word1, word2, dp);
    int replaceOp = 1 + solver(i + 1, j + 1, word1, word2, dp);

    return dp[i][j] = min({insertOp, deleteOp, replaceOp});
}

int minDistance(string word1, string word2)
{
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solver(0, 0, word1, word2, dp);
}