#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case:
        // word1 exhausted -> insert remaining word2 chars
        for (int j = 0; j <= m; j++)
        {
            dp[n][j] = m - j;
        }

        // Base case:
        // word2 exhausted -> delete remaining word1 chars
        for (int i = 0; i <= n; i++)
        {
            dp[i][m] = n - i;
        }

        // Fill from back
        for (int i = n - 1; i >= 0; i--)
        {

            for (int j = m - 1; j >= 0; j--)
            {

                if (word1[i] == word2[j])
                {

                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {

                    int insertOp = 1 + dp[i][j + 1];
                    int deleteOp = 1 + dp[i + 1][j];
                    int replaceOp = 1 + dp[i + 1][j + 1];

                    dp[i][j] = min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[0][0];
    }
};