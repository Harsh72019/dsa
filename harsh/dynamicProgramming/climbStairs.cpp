#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dp = vector<int>(46, -1);
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
