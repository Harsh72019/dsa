#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    long long prefixSum = 0;
    unordered_map<int, int> prefixCounts;
    prefixCounts[0] = 1;
    int totalCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        int compliment = prefixSum - k;
        if (prefixCounts.find(compliment) != prefixCounts.end())
        {
            totalCount += prefixCounts[compliment];
        }
        prefixCounts[prefixSum]++;
    }
    return totalCount;
}