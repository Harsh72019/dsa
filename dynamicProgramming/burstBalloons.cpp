#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[302][302]; 

    int solve(int i, int j, vector<int>& nums) {
        if (i + 1 == j) return 0; 

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;

        for (int k = i + 1; k < j; ++k) {
            int coins = nums[i] * nums[k] * nums[j];
            coins += solve(i, k, nums) + solve(k, j, nums);
            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        memset(dp, -1, sizeof(dp));

        return solve(0, n + 1, nums);
    }
};
