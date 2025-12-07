#include <bits/stdc++.h>
using namespace std;
void visit(vector<vector<char>> &grid, int row, int col)
{
    if (row >= grid.size() || col >= grid[0].size() || col < 0 || row < 0 || grid[row][col] != '1')
        return;
    grid[row][col] = 'X';
    visit(grid, row + 1, col);
    visit(grid, row, col + 1);
    visit(grid, row, col - 1);
    visit(grid, row - 1, col);
}
int numIslands(vector<vector<char>> &grid)
{
    int ans = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == '1')
            {
                visit(grid, row, col);
                ans++;
            }
        }
    }
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == 'X')
            {
                grid[row][col] = '1';
            }
        }
    }
    return ans;
}