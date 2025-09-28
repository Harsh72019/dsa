#include<bits/stdc++.h>
using namespace std;


int solver(int i, int transactions, int holding, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || transactions == 2)
            return 0;

        if (dp[i][transactions][holding] != -1)
            return dp[i][transactions][holding];

        int doNothing = solver(i + 1, transactions, holding, prices, dp);
        int doSomething;

        if (holding) {
            doSomething = prices[i] + solver(i + 1, transactions + 1, 0, prices, dp);
        } else {
            doSomething = -prices[i] + solver(i + 1, transactions, 1, prices, dp);
        }

        return dp[i][transactions][holding] = max(doNothing, doSomething);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1))); 
        return solver(0, 0, 0, prices, dp);
    }