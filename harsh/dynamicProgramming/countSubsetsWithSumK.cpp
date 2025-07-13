#include<bits/stdc++.h>
using namespace std;

 int solver(int index, vector<int>& arr, int sum, int target, vector<vector<int>>& dp) {
        if (sum == target)
            return 1;
        if (index >= arr.size() || sum > target)
            return 0;
        if (dp[index][sum] != -1)
            return dp[index][sum];

        int pick = solver(index + 1, arr, sum + arr[index], target, dp);
        int notPick = solver(index + 1, arr, sum, target, dp);

        return dp[index][sum] = pick + notPick;
    }

    int perfectSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solver(0, arr, 0, k, dp);
    }