#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LIS(vector<int> &arr)
    {
        vector<int> temp;

        for (int x : arr)
        {
            auto it = lower_bound(temp.begin(), temp.end(), x);
            if (it == temp.end())
                temp.push_back(x);
            else
                *it = x;
        }

        return temp.size();
    }

    int longestSubsequence(vector<int> &nums)
    {
        int ans = 0;

        for (int bit = 0; bit < 32; bit++)
        {
            vector<int> filtered;

            for (int x : nums)
            {
                if (x & (1 << bit))
                {
                    filtered.push_back(x);
                }
            }

            if (!filtered.empty())
            {
                ans = max(ans, LIS(filtered));
            }
        }

        return ans;
    }
};