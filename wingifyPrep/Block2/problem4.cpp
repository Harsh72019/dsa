#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int prefixSum = 0;
    unordered_map<long long, int> preInd;
    int ans = 0;
    preInd[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        int compliment = prefixSum - k;
        if (preInd.find(compliment) != preInd.end())
            ans += preInd[compliment];
        preInd[prefixSum]++;
    }
    return ans;
}