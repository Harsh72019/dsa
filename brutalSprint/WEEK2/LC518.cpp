#include <bits/stdc++.h>
using namespace std;

int solver(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 1;
    if (index >= coins.size())
        return 0;
    if (dp[index][amount] != -1)
        return dp[index][amount];
    int notTake = solver(index + 1, amount, coins, dp);
    int take = 0;
    if (amount - coins[index] >= 0)
        take = solver(index, amount - coins[index], coins, dp);
    return dp[index][amount] = take + notTake;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return solver(0, amount, coins, dp);
}