#include<bits/stdc++.h>
using namespace std;


    int solver(vector<int>& wt, vector<int>& val, int index, int w, vector<vector<int>>& dp) {
        if (w == 0)
            return 0;
        if (index >= wt.size())
            return 0;  
        if (dp[index][w] != -1)
            return dp[index][w];
        
        int notTake = solver(wt, val, index + 1, w, dp);  
        int take = 0;
        if (wt[index] <= w)
            take = val[index] + solver(wt, val, index, w - wt[index], dp);  
        
        return dp[index][w] = max(take, notTake);
    }

    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solver(wt, val, 0, W, dp);
    }

