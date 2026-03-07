#include <bits/stdc++.h>
using namespace std;

bool solver(string s, vector<string> &wordDict, int index, vector<int> &dp)
{
    if (index >= s.size())
        return true;
    if (dp[index] != -1)
        return dp[index];

    for (auto word : wordDict)
    {
        int len = word.size();
        if (s.substr(index, len) == word)
        {
            if (solver(s, wordDict, index + len, dp))
                return dp[index] = true;
        }
    }
    return dp[index] = false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return solver(s, wordDict, 0, dp);
}