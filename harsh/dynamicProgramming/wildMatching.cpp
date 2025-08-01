#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    bool solve(int i, int j, string& s, string& p) {
        if (i < 0 && j < 0) return true;
        if (i < 0) {
            for (int k = 0; k <= j; ++k)
                if (p[k] != '*') return false;
            return true;
        }
        if (j < 0) return false;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p);

        if (p[j] == '*') {
            return dp[i][j] = solve(i - 1, j, s, p) || solve(i, j - 1, s, p);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        n = s.size(), m = p.size();
        dp.resize(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s, p);
    }
};
