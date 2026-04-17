#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        unordered_map<char, int> need;
        for (char i : t)
            need[i]++;
        int start = 0;
        int minLen = INT_MAX;
        int right = 0, left = 0;
        unordered_map<char, int> window;
        int required = need.size();
        int formed = 0;

        while (right < m)
        {
            char current = s[right];
            window[current]++;
            if (need.count(current) && window[current] == need[current])
            {
                formed++;
            }

            while (left <= right && formed == required)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }

                char toRemove = s[left];
                window[toRemove]--;
                if (need.count(toRemove) && window[toRemove] < need[toRemove])
                {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};