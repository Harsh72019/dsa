#include <bits/stdc++.h>
using namespace std;

int dominantIndices(vector<int> &nums)
{
    int n = nums.size();
    int total = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        total += nums[i];
        int avg = total / (n - i);
        if (avg < nums[i])
            ans++;
    }
    return ans;
}