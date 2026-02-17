#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int INF = 1e8;
    vector<vector<vector<int>>> dp;

    int solver(vector<int>& houses,
               vector<vector<int>>& cost,
               int index,
               int n,
               int target,
               int prevCol) {

        if (target < 0)
            return INF;

        if (index == houses.size())
            return target == 0 ? 0 : INF;

        if (dp[index][target][prevCol] != -1)
            return dp[index][target][prevCol];

        int ans = INF;

        if (houses[index] != 0) {
            int color = houses[index];
            int newTarget = target - (color != prevCol);
            ans = solver(houses, cost, index + 1, n, newTarget, color);
        }
        else {
            for (int color = 1; color <= n; color++) {
                int newTarget = target - (color != prevCol);
                int sub = solver(houses, cost, index + 1, n, newTarget, color);
                ans = min(ans, cost[index][color - 1] + sub);
            }
        }

        return dp[index][target][prevCol] = ans;
    }

    int minCost(vector<int>& houses,
                vector<vector<int>>& cost,
                int m,
                int n,
                int target) {

        dp.assign(m, vector<vector<int>>(target + 1,
                 vector<int>(n + 1, -1)));

        int ans = solver(houses, cost, 0, n, target, 0);

        return ans == INF ? -1 : ans;
    }
};
