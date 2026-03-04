#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row , int col , vector<vector<char>> & grid)
    {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1')
            return;
        grid[row][col] = 'X';
        dfs(row + 1 ,  col , grid);
        dfs(row - 1 ,  col , grid);
        dfs(row ,  col + 1 , grid);
        dfs(row ,  col - 1 , grid); 
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        for(int row = 0 ; row <  rows ; row++)
        {
            for(int col = 0 ; col < cols ; col++)
            {
                if(grid[row][col] == '1')
                {
                    dfs(row , col , grid);
                    islands++;
                }
            }
        }
        for(int row = 0 ; row <  rows ; row++)
        {
            for(int col = 0 ; col < cols ; col++)
            {
                if(grid[row][col] == 'X')
                {
                    grid[row][col] == '1';
                }
            }
        }
        return islands;
    }
};