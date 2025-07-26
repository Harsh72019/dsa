#include <bits/stdc++.h>
using namespace std;

int solver(int i, int holding, vector<int> &prices, vector<vector<int>> &dp, int fee)
{
    if (i == prices.size())
        return 0;

    if (dp[i][holding] != -1)
        return dp[i][holding];

    int doNothing = solver(i + 1, holding, prices, dp, fee);
    int doSomething;

    if (holding)
    {
        doSomething = prices[i] - fee + solver(i + 1, 0, prices, dp, fee);
    }
    else
    {
        doSomething = -prices[i] + solver(i + 1, 1, prices, dp, fee);
    }

    return dp[i][holding] = max(doNothing, doSomething);
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solver(0, 0, prices, dp, fee);
}