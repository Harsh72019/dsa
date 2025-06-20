#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int row, int col)
{
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1)
        return;
    grid[row][col] = 2;
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}
int numEnclaves(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++)
    {
        if (grid[i][0] == 1)
            dfs(grid, i, 0);
        if (grid[i][cols - 1] == 1)
            dfs(grid, i, cols - 1);
    }

    for (int i = 0; i < cols; i++)
    {
        if (grid[0][i] == 1)
            dfs(grid, 0, i);
        if (grid[rows - 1][i] == 1)
            dfs(grid, rows - 1, i);
    }
    int counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 2)
                grid[i][j] = 1;
            else if (grid[i][j] == 1)
                counter++;
        }
    }
    return counter;
}