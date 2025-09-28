#include<bits/stdc++.h>
using namespace std;


    int solver(int index, int n, vector<int>& price, vector<vector<int>>& dp) {
        if (index == 0) {
            return price[0] * n;
        }

        if (dp[index][n] != -1)
            return dp[index][n];

        int notTake = solver(index - 1, n, price, dp);
        int take = INT_MIN;
        int rodLength = index + 1;

        if (rodLength <= n) {
            take = price[index] + solver(index, n - rodLength, price, dp);
        }

        return dp[index][n] = max(take, notTake);
    }

    int rodCutting(vector<int> price, int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solver(n - 1, n, price, dp);
    }

