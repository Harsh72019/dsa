#include <bits/stdc++.h>
using namespace std;

int findSmallestInteger(vector<int> &nums, int value)
{
    int n = nums.size();
    vector<int> cnt(value, 0);
    for (int a : nums)
    {
        int r = ((a % value) + value) % value;
        cnt[r]++;
    }

    for (int x = 0; x <= n; ++x)
    {
        int r = x % value;
        if (cnt[r] > 0)
        {
            cnt[r]--;
        }
        else
        {
            return x;
        }
    }

    return n;
}