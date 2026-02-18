#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int solver(vector<int>& nums,
               vector<int>& multipliers,
               int start,
               int multiIndex) {

        if (multiIndex == multipliers.size())
            return 0;

        if (dp[start][multiIndex] != INT_MIN)
            return dp[start][multiIndex];

        int n = nums.size();
        int end = n - 1 - (multiIndex - start);

        int toMul = multipliers[multiIndex];

        int takeFirst =
            nums[start] * toMul +
            solver(nums, multipliers, start + 1, multiIndex + 1);

        int takeLast =
            nums[end] * toMul +
            solver(nums, multipliers, start, multiIndex + 1);

        return dp[start][multiIndex] =
               max(takeFirst, takeLast);
    }

    int maximumScore(vector<int>& nums,
                     vector<int>& multipliers) {

        int m = multipliers.size();

        dp.assign(m, vector<int>(m, INT_MIN));

        return solver(nums, multipliers, 0, 0);
    }
};
