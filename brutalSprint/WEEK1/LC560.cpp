#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> um;
    um[0] = 1;
    int ans = 0;
    int prefixSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        int compliment = prefixSum - k;
        if (um.find(compliment) != um.end())
            ans += um[compliment];
        um[prefixSum]++;
    }
    return ans;
}