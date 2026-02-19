#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int mod = 1e9 + 7;

public:
    int solver(vector<int> &locations, int start, int finish, int fuel, vector<vector<int>> &dp)
    {
        if (fuel < 0)
            return 0;
        if (dp[start][fuel] != -1)
            return dp[start][fuel];
        int total = (start == finish) ? 1 : 0;
        for (int i = 0; i < locations.size(); i++)
        {
            if (i != start)
            {
                int fuelConsumed = abs(locations[start] - locations[i]);
                total = (total + solver(locations, i, finish, fuel - fuelConsumed, dp)) % mod;
            }
        }
        return dp[start][fuel] = total % mod;
    }
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
        return solver(locations, start, finish, fuel, dp);
    }
};