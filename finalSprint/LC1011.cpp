#include <bits/stdc++.h>
using namespace std;

bool canShip(vector<int> &weights, int days, int weight)
{
    int totalDays = 1;
    int currentCap = 0;
    for (auto it : weights)
    {
        if (currentCap + it > weight)
        {
            totalDays++;
            currentCap = it;
        }
        else
            currentCap += it;
    }
    return totalDays <= days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (canShip(weights, days, mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}