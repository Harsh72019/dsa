#include <bits/stdc++.h>
using namespace std;

long long gcdSum(vector<int> &nums)
{
    int n = nums.size();
    int largestYet = -1;
    vector<int> prefixGcd(n);
    for (int i = 0; i < n; i++)
    {
        largestYet = max(largestYet, nums[i]);
        prefixGcd[i] = gcd(nums[i], largestYet);
    }
    sort(prefixGcd.begin(), prefixGcd.end());
    long long ans = 0;
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        ans += gcd(prefixGcd[left], prefixGcd[right]);
        left++;
        right--;
    }
    return ans;
}