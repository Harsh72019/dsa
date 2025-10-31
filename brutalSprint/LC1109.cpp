#include <bits/stdc++.h>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> ans(n, 0);
    for (auto it : bookings)
    {
        ans[it[0] - 1] += it[2];
        if (it[1] < n)
        {
            ans[it[1]] -= it[2];
        }
    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        sum += ans[i];
        ans[i] = sum;
    }
    return ans;
}