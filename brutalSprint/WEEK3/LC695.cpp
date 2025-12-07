#include <bits/stdc++.h>
using namespace std;

int visit(vector<vector<int>> &grid, int row, int col)
{
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1)
        return 0;
    grid[row][col] = -1;
    int down = visit(grid, row + 1, col);
    int right = visit(grid, row, col + 1);
    int up = visit(grid, row - 1, col);
    int left = visit(grid, row, col - 1);
    return 1 + down + right + up + left;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    if (grid.empty() || grid[0].empty())
        return 0;
    int ans = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            if (grid[row][col] == 1)
            {
                ans = max(ans, visit(grid, row, col));
            }
        }
    }
    return ans;
}