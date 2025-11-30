#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &weights, int days, int capacity)
{
    int daysUsed = 1;
    int currentLoad = 0;

    for (int w : weights)
    {
        if (currentLoad + w > capacity)
        {
            daysUsed++;
            currentLoad = 0;
        }
        currentLoad += w;

        if (daysUsed > days)
            return false;
    }
    return true;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int minEle = *max_element(weights.begin(), weights.end());
    int maxEle = accumulate(weights.begin(), weights.end(), 0);
    int mid = 0;
    int ans = INT_MAX;
    while (minEle <= maxEle)
    {
        mid = minEle + (maxEle - minEle) / 2;
        if (check(weights, days, mid))
        {
            ans = min(ans, mid);
            maxEle = mid - 1;
        }
        else
            minEle = mid + 1;
    }
    return ans;
}