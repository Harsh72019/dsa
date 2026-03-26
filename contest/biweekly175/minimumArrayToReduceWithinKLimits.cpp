#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long nonPositive(vector<int> &nums, int k)
    {
        long long op = 0;
        for (int x : nums)
        {
            op += (x + k - 1) / k;
        }
        return op;
    }

    int minimumK(vector<int> &nums)
    {
        int lo = 1;
        int hi = 100000;
        int ans = hi;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            long long op = nonPositive(nums, mid);

            if (op <= 1LL * mid * mid)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};