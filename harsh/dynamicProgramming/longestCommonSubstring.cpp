#include<bits/stdc++.h>
using namespace std;


    int solver(int i, int j, string &str1, string &str2, vector<vector<int>> &dp, int &maxLen) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (str1[i] == str2[j]) {
            dp[i][j] = 1 + solver(i - 1, j - 1, str1, str2, dp, maxLen);
            maxLen = max(maxLen, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }

        solver(i - 1, j, str1, str2, dp, maxLen);
        solver(i, j - 1, str1, str2, dp, maxLen);

        return dp[i][j];
    }

    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLen = 0;
        solver(n - 1, m - 1, str1, str2, dp, maxLen);
        return maxLen;
    }
