#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        int start = 0;
        int end = 0;
        int prev = prices[0] + 1;
        long long total = 0;
        for (int i = end; i < prices.size(); i++)
        {
            if (prev - prices[i] == 1)
            {
                prev = prices[i];
                long long toAdd = i - start + 1;
                total += toAdd;
            }
            else
            {
                prev = prices[i];
                start = i;
                total++;
            }
        }
        return total;
    }
};