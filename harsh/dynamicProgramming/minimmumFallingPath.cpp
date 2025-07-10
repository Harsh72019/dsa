#include<bits/stdc++.h>
using namespace std;


    int solver(int row , int col , vector<vector<int>>& matrix , vector<vector<int>> & dp)
    {
        int n = matrix.size(), m = matrix[0].size();

        if(row >= n || col < 0 || col >= m)
            return 1e9;

        if(row == n - 1)
            return matrix[row][col];

        if(dp[row][col] != -1)
            return dp[row][col];

        int down = solver(row + 1 , col , matrix , dp);
        int downLeft = solver(row + 1 , col - 1 , matrix , dp);
        int downRight = solver(row + 1 , col + 1 , matrix , dp);

        return dp[row][col] =  matrix[row][col] + min({down, downLeft, downRight});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        int ans = INT_MAX;

        for(int col = 0 ; col < m ; col++) {
            ans = min(ans , solver(0 , col , matrix , dp));
        }

        return ans;
    }
