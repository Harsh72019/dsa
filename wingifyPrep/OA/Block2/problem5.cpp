#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int prefixSum = 0;
    unordered_map<int, int> remCount;
    remCount[0] = 1;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        int rem = prefixSum % k;
        if (rem < 0)
            rem += k;
        if (remCount.find(rem) != remCount.end())
            ans += remCount[rem];
        remCount[rem]++;
    }
    return ans;
}