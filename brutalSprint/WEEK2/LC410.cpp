#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums, int mid, int k)
{
    int currentSum = 0;
    int usedNums = 0;
    for (auto i : nums)
    {
        if (i + currentSum > mid)
        {
            usedNums++;
            currentSum = i;
            if (usedNums >= k)
                return false;
        }
        else
        {
            currentSum += i;
        }
    }
    return true;
}

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(nums, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}