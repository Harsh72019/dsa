#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, vector<int> &target)
{
    int totalOps = 0;
    int n = nums.size();
    set<int> converted;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != target[i])
        {
            if (converted.find(nums[i]) == converted.end())
            {
                converted.insert(nums[i]);
                totalOps++;
            }
        }
    }
    return totalOps;
}