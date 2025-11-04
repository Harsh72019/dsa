#include <bits/stdc++.h>
using namespace std;

bool carPooling(vector<vector<int>> &trips, int capacity)
{
    map<int, int> changes; 
    for (auto &trip : trips)
    {
        changes[trip[1]] += trip[0];
        changes[trip[2]] -= trip[0];
    }

    int sum = 0;
    for (auto &entry : changes)
    {
        sum += entry.second;
        if (sum > capacity)
            return false;
    }
    return true;
}
