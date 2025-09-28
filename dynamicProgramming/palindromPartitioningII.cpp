#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int start, int end, string &s)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int solver(int start, string &s, vector<int> &dp)
{
    if (start == s.size())
        return 0;

    if (dp[start] != -1)
        return dp[start];

    int mini = INT_MAX;

    for (int i = start; i < s.size(); i++)
    {
        if (isPalindrome(start, i, s))
        {
            int take = 1 + solver(i + 1, s, dp);
            mini = min(mini, take);
        }
    }
    return dp[start] = mini;
}

int minCut(string s)
{
    vector<int> dp(s.size(), -1);
    return solver(0, s, dp) - 1;
}