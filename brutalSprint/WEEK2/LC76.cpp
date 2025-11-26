#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    if (t.size() > s.size())
        return "";

    unordered_map<char, int> need;
    for (char c : t)
        need[c]++;

    int required = need.size();
    int formed = 0;

    unordered_map<char, int> window;
    int l = 0, r = 0;
    int bestLen = INT_MAX;
    int bestL = 0;

    while (r < s.size())
    {
        char c = s[r];
        window[c]++;

        if (need.count(c) && window[c] == need[c])
            formed++;

        // try to shrink
        while (l <= r && formed == required)
        {
            if (r - l + 1 < bestLen)
            {
                bestLen = r - l + 1;
                bestL = l;
            }

            char leftChar = s[l];
            window[leftChar]--;

            if (need.count(leftChar) && window[leftChar] < need[leftChar])
                formed--;

            l++;
        }

        r++;
    }

    return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
}