#include <bits/stdc++.h>
using namespace std;

bool canEat(vector<int> &piles, int h, int bananas)
{
    int hoursTaken = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        int hour = (piles[i] + bananas - 1) / bananas;
        hoursTaken += hour;
        if (hoursTaken > h)
            return false;
    }
    return true;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (canEat(piles, h, mid))
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return left;
}
