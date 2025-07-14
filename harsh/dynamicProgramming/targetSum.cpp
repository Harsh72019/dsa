#include<bits/stdc++.h>
using namespace std;


 int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if ((target + totalSum) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int sum = (target + totalSum) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;  

        for (int i = 1; i <= n; ++i) {
            for (int s = 0; s <= sum; ++s) {
                dp[i][s] = dp[i - 1][s];
                if (s >= nums[i - 1])
                    dp[i][s] += dp[i - 1][s - nums[i - 1]];
            }
        }

        return dp[n][sum];
    }