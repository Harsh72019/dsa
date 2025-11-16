#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> um;
    int i = 0;
    int ans = 0;

    for (int j = 0; j < s.size(); j++)
    {
        if (um.find(s[j]) != um.end())
        {
            i = max(i, um[s[j]] + 1);
        }
        um[s[j]] = j;
        ans = max(ans, j - i + 1);
    }

    return ans;
}