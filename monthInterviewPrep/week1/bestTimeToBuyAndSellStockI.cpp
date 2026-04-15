#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int currentMin = INT_MAX;
        int maxProfit = 0;
        for (auto price : prices)
        {
            currentMin = min(currentMin, price);
            maxProfit = max(maxProfit, price - currentMin);
        }
        return maxProfit;
    }
};