#include <bits/stdc++.h>
using namespace std;

string solver(int i, int j, string &text1, string &text2, vector<vector<string>> &dp)
{
    if (i >= text1.size() || j >= text2.size())
    {
        return "";
    }

    if (dp[i][j] != "")
        return dp[i][j];

    if (text1[i] == text2[j])
    {
        dp[i][j] = text1[i] + solver(i + 1, j + 1, text1, text2, dp);
    }
    else
    {
        string opt1 = solver(i + 1, j, text1, text2, dp);
        string opt2 = solver(i, j + 1, text1, text2, dp);
        dp[i][j] = (opt1.length() > opt2.length()) ? opt1 : opt2;
    }

    return dp[i][j];
}

string longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size(), m = text2.size();
    vector<vector<string>> dp(n, vector<string>(m, ""));
    return solver(0, 0, text1, text2, dp);
}
  