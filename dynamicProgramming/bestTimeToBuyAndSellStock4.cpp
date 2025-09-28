#include <bits/stdc++.h>
using namespace std;

int solver(int i, int transactions, int holding, vector<int> &prices, vector<vector<vector<int>>> &dp, int k)
{
    if (i == prices.size() || transactions == k)
        return 0;

    if (dp[i][transactions][holding] != -1)
        return dp[i][transactions][holding];

    int doNothing = solver(i + 1, transactions, holding, prices, dp, k);
    int doSomething;

    if (holding)
    {
        doSomething = prices[i] + solver(i + 1, transactions + 1, 0, prices, dp, k);
    }
    else
    {
        doSomething = -prices[i] + solver(i + 1, transactions, 1, prices, dp, k);
    }

    return dp[i][transactions][holding] = max(doNothing, doSomething);
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    return solver(0, 0, 0, prices, dp, k);
}