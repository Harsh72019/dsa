#include<bits/stdc++.h>
using namespace std;


bool solver(int index, vector<int>& arr, int sum, int target, vector<vector<int>>& dp) {
    if (sum == target)
        return true;
    if (index >= arr.size() || sum > target)
        return false;
    if (dp[index][sum] != -1)
        return dp[index][sum];

    bool pick = solver(index + 1, arr, sum + arr[index], target, dp);
    bool notPick = solver(index + 1, arr, sum, target, dp);

    return dp[index][sum] = pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solver(0, arr, 0, k, dp);
}
