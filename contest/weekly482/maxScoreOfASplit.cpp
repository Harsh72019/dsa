#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumScore(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> mins(n);
        int currentMin = nums[n - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            currentMin = min(currentMin, nums[i]);
            mins[i] = currentMin;
        }

        long long prefixSum = 0;
        long long score = LLONG_MIN;

        for (int i = 0; i < n - 1; i++)
        {
            prefixSum += nums[i];
            score = max(score, prefixSum - mins[i + 1]);
        }

        return score;
    }
};