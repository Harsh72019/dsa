#include <bits/stdc++.h>
using namespace std;

bool canSplit(vector<int> &nums, int k, int maxSum)
{
    int currentSum = 0;
    int pieces = 1;

    for (int num : nums)
    {
        if (currentSum + num > maxSum)
        {
            pieces++;
            currentSum = num;
        }
        else
        {
            currentSum += num;
        }
    }

    return pieces <= k;
}

int splitArray(vector<int> &nums, int k)
{
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (canSplit(nums, k, mid))
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}