#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int lcsLen(int i, int j, string &s1, string &s2) {
        if (i == s1.size() || j == s2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + lcsLen(i + 1, j + 1, s1, s2);

        return dp[i][j] = max(lcsLen(i + 1, j, s1, s2), lcsLen(i, j + 1, s1, s2));
    }

    string buildSCS(string &s1, string &s2) {
        string scs = "";
        int i = 0, j = 0;

        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                scs += s1[i];
                i++;
                j++;
            }
            else if (dp[i + 1][j] >= dp[i][j + 1]) {
                scs += s1[i];
                i++;
            }
            else {
                scs += s2[j];
                j++;
            }
        }

        while (i < s1.size()) scs += s1[i++];
        while (j < s2.size()) scs += s2[j++];

        return scs;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        lcsLen(0, 0, str1, str2);
        return buildSCS(str1, str2);
    }
};
