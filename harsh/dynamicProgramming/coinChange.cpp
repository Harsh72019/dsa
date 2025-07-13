#include<bits/stdc++.h>
using namespace std;

 int solver(int i, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if(target == 0 )
            return 0;
        if(i >= coins.size())
            return 1e9;
        if(dp[i][target] != -1)
            return dp[i][target];
        int notTake = solver(i  + 1 , target , coins , dp);
        int take = 1e9;
        if(coins[i] <= target)
            take = 1 + solver( i , target - coins[i] , coins , dp);
        return dp[i][target] =  min(take , notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solver(0, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }