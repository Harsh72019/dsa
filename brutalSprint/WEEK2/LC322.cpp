#include <bits/stdc++.h>
using namespace std;

int solver(vector<int> &coins, int index, int amount, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 0;
    if (index >= coins.size())
        return 10e8;
    if (dp[index][amount] != -1)
        return dp[index][amount];
    int take = 10e8;
    if ((amount - coins[index]) >= 0)
        take = 1 + solver(coins, index, amount - coins[index], dp);
    int notTake = 0 + solver(coins, index + 1, amount, dp);
    return dp[index][amount] = min(take, notTake);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(10000 + 1, -1));
    int ans = solver(coins, 0, amount, dp);
    return ans == 10e8 ? -1 : ans;
}