#include <bits/stdc++.h>
using namespace std;

int solver(vector<vector<int>> &points, int index, int current, vector<vector<int>> &dp) {
    if (index < 0) return 0;

    if (dp[index][current + 1] != -1) 
        return dp[index][current + 1];

    int ans = INT_MIN;
    for (int i = 0; i < 3; i++) {
        if (current == i) continue;
        int val = solver(points, index - 1, i, dp) + points[index][i];
        ans = max(ans, val);
    }

    return dp[index][current + 1] = ans;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solver(points, n - 1, -1, dp);
}
