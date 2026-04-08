#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minCost(string s, vector<int> &cost)
    {
        long long freq[26] = {0};
        long long total = 0, maxKeep = 0;

        for (int i = 0; i < s.size(); i++)
        {
            total += cost[i];
            freq[s[i] - 'a'] += cost[i];
            maxKeep = max(maxKeep, freq[s[i] - 'a']);
        }

        return total - maxKeep;
    }
};