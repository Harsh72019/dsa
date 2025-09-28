#include<bits/stdc++.h>
using namespace std;

 int solver(int index , int target  , vector<int>& coins , vector<vector<int>>& dp)
    {
        if(target == 0)
            return 1;
        if(index >= coins.size() || target < 0)
            return 0;
        if(dp[index][target] != -1)
            return dp[index][target];
        int notTake = solver(index + 1, target , coins , dp );
        int take = 0;
        if(coins[index] <= target)
            take = solver(index , target - coins[index] , coins , dp);
        return dp[index][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1, -1));
        return solver(0 , amount , coins , dp);
    }