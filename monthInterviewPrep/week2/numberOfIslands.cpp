#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void traverseIsland(vector<vector<char>>& grid , int row , int col)
    {
        if(row < 0 || row == grid.size() || col < 0 || col == grid[0].size() || grid[row][col] != '1')
            return;
        grid[row][col] = 'X';
        traverseIsland(grid , row + 1 , col);
        traverseIsland(grid , row - 1 , col);
        traverseIsland(grid , row , col + 1);
        traverseIsland(grid , row , col - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int numOfIslands = 0;
        for(int row = 0 ; row < rows ; row++)
        {
            for(int col = 0 ; col < cols ; col++)
            {
                if(grid[row][col] == '1')
                {
                    traverseIsland(grid , row , col);
                    numOfIslands++;
                }
            }
        }
        for(int row = 0 ; row < rows ; row++)
        {
            for(int col = 0 ; col < cols ; col++)
            {
                if(grid[row][col] == 'X')
                {
                    grid[row][col] = '1';
                }
            }
        }
        return numOfIslands;
    }
};