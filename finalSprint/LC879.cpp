#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int solver(int people,
               int minProfit,
               vector<int> &group,
               vector<int> &profit,
               int index,
               vector<vector<vector<int>>> &dp)
    {
        if (people < 0)
            return 0;

        if (index == group.size())
            return minProfit == 0 ? 1 : 0;

        if (dp[index][people][minProfit] != -1)
            return dp[index][people][minProfit];

        int newProfit =
            max(0, minProfit - profit[index]);

        int take =
            solver(people - group[index],
                   newProfit,
                   group,
                   profit,
                   index + 1,
                   dp);

        int noTake =
            solver(people,
                   minProfit,
                   group,
                   profit,
                   index + 1,
                   dp);

        return dp[index][people][minProfit] =
                   (take + noTake) % mod;
    }

    int profitableSchemes(int n,
                          int minProfit,
                          vector<int> &group,
                          vector<int> &profit)
    {
        int m = group.size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n + 1,
                                vector<int>(minProfit + 1, -1)));

        return solver(n,
                      minProfit,
                      group,
                      profit,
                      0,
                      dp);
    }
};