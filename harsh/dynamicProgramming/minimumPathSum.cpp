#include<bits/stdc++.h>
using namespace std;

    int solver(vector<vector<int>> & grid , int row , int col ,vector<vector<int>> & dp)
    {
        if(row < 0 || col < 0)
            return INT_MAX;
        if( row == 0 && col == 0)
            return grid[0][0];
        if(dp[row][col] != -1)
            return dp[row][col];
        int left = solver(grid , row , col - 1 , dp);
        int right = solver(grid ,  row - 1 ,col , dp);
        return dp[row][col] = grid[row][col] + min(left , right);            
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows , vector<int>(cols , -1));
        return solver(grid , rows -1 , cols - 1 , dp);
    }