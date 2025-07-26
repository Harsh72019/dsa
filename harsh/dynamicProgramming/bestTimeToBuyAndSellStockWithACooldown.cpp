#include <bits/stdc++.h>
using namespace std;

int solver(int i, int holding, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i >= prices.size())
        return 0;

    if (dp[i][holding] != -1)
        return dp[i][holding];

    int doNothing = solver(i + 1, holding, prices, dp);
    int doSomething;

    if (holding)
    {
        doSomething = prices[i] + solver(i + 2, 0, prices, dp);
    }
    else
    {
        doSomething = -prices[i] + solver(i + 1, 1, prices, dp);
    }

    return dp[i][holding] = max(doNothing, doSomething);
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, -1));
    return solver(0, 0, prices, dp);
}