#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = INT_MIN;
    int currentMin = INT_MAX;
    for (auto it : prices)
    {
        currentMin = min(currentMin, it);
        maxProfit = max(maxProfit, it - currentMin);
    }
    return maxProfit;
}