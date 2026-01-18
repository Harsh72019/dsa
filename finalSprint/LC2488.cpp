#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> &nums, int k)
{
    const int n = nums.size();
    int mid = find(nums.begin(), nums.end(), k) - nums.begin();
    vector<int> cnt(2 * n + 3, 0);
    ++cnt[n];
    int bal = 0;
    for (int i = mid + 1; i < n; ++i)
    {
        bal += (nums[i] > k) ? 1 : -1;
        ++cnt[bal + n];
    }
    int res = cnt[n] + cnt[n + 1];
    bal = 0;
    for (int i = mid - 1; i >= 0; --i)
    {
        bal += (nums[i] > k) ? 1 : -1;
        res += cnt[n - bal] + cnt[n - bal + 1];
    }
    return res;
}