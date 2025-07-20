#include <bits/stdc++.h>
using namespace std;

int solver(int index1, int index2, string &word1, string &word2, vector<vector<int>> &dp)
{
    if (index1 >= word1.size() || index2 >= word2.size())
    {
        return 0;
    }
    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }
    if (word1[index1] == word2[index2])
    {
        return dp[index1][index2] = 2 + solver(index1 + 1, index2 + 1, word1, word2, dp);
    }
    return dp[index1][index2] = max(solver(index1 + 1, index2, word1, word2, dp), solver(index1, index2 + 1, word1, word2, dp));
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int totalSize = n + m;
    return totalSize - solver(0, 0, word1, word2, dp);
}