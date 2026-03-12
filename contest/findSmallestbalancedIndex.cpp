#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestBalancedIndex(vector<int> &nums)
    {
        int n = nums.size();
        const long long LIMIT = 1e15;

        vector<long long> product(n, 1);
        long long currentProduct = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            product[i] = currentProduct;
            if (currentProduct > LIMIT / nums[i])
                currentProduct = LIMIT;
            else
                currentProduct *= nums[i];
        }

        long long prefixSum = 0;

        for (int i = 0; i < n; i++)
        {
            if (prefixSum == product[i])
                return i;
            prefixSum += nums[i];
        }

        return -1;
    }
};