#include <bits/stdc++.h>
using namespace std;

string shortestPalindrome(string s)
{
    auto computeLPS = [](const string &pattern) -> vector<int>
    {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int length = 0;
        int i = 1;

        while (i < n)
        {
            if (pattern[i] == pattern[length])
            {
                length++;
                lps[i] = length;
                i++;
            }
            else
            {
                if (length != 0)
                {
                    length = lps[length - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    };

    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string combined = s + "#" + rev_s;
    vector<int> lps = computeLPS(combined);
    int to_add_len = s.size() - lps.back();
    string to_add = rev_s.substr(0, to_add_len);
    return to_add + s;
}