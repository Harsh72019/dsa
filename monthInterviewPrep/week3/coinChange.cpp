#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solver(int index  , vector<int>& coins , int amount , vector<vector<int>>& dp)
    {
        if(index >= coins.size() || amount < 0)
            return 1e9;
        if(amount == 0)
            return 0;
        if(dp[index][amount] != -1)
            return dp[index][amount];
        int notPick = solver(index + 1 , coins , amount , dp);
        int pick = 1 + solver(index , coins , amount - coins[index] , dp);
        return dp[index][amount] = min(notPick , pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1 , -1));
        int ans = solver(0,  coins , amount , dp);
        return ans >= 1e9 ? -1 : ans;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        int INF = 1e9;

        vector<vector<int>> dp(n + 1,
                               vector<int>(amount + 1, INF));

        // amount 0 needs 0 coins
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // fill bottom-up
        for(int index = n - 1; index >= 0; index--) {

            for(int amt = 1; amt <= amount; amt++) {

                int notPick = dp[index + 1][amt];

                int pick = INF;

                if(amt >= coins[index]) {
                    pick = 1 + dp[index][amt - coins[index]];
                }

                dp[index][amt] = min(notPick, pick);
            }
        }

        int ans = dp[0][amount];

        return ans >= INF ? -1 : ans;
    }
};