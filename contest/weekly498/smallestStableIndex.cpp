#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> mins(n, 0);
        int currMin = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            currMin = min(currMin, nums[i]);
            mins[i] = currMin;
        }
        int currMax = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            currMax = max(nums[i], currMax);
            if (currMax - mins[i] <= k)
                return i;
        }
        return -1;
    }
};