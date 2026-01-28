#include <bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums, int k)
{
    int left = 0, odds = 0, ans = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] % 2)
            odds++;

        while (odds > k)
        {
            if (nums[left] % 2)
                odds--;
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    return atMost(nums, k) - atMost(nums, k - 1);
}