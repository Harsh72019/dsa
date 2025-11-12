#include <bits/stdc++.h>
using namespace std;

// Brute force recursive to Climb Stairs
class Solution
{
public:
    int solve(int n, int steps)
    {
        if (steps > n)
            return 0;
        if (steps == n)
            return 1;
        int oneStep = solve(n, steps + 1);
        int twoStep = solve(n, steps + 2);
        return oneStep + twoStep;
    }
    int climbStairs(int n)
    {
        return solve(n, 0);
    }
};

// Optimized DP apprach
class SolutionDP
{
public:
    int solve(int n, int steps, vector<int> &dp)
    {
        if (steps > n)
            return 0;
        if (steps == n)
            return 1;
        if (dp[steps] != -1)
            return dp[steps];
        int oneStep = solve(n, steps + 1, dp);
        int twoStep = solve(n, steps + 2, dp);
        return dp[steps] = oneStep + twoStep;
    }
    int climbStairs(int n)
    {
        vector<int> dp(n, -1);
        return solve(n, 0, dp);
    }
};

// Optimized Tabulated approaach
class SolutionTabulated
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};