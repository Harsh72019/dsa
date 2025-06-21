#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int row, int col, string &path, string direction)
{
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1)
        return;
    grid[row][col] = 2;
    path += direction;
    dfs(grid, row, col + 1, path, "L");
    dfs(grid, row + 1, col, path, "D");
    dfs(grid, row, col - 1, path, "R");
    dfs(grid, row + 1, col, path, "U");
    path += 'B';
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    unordered_set<string> st;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                string path = "";
                dfs(grid, i, j, path, "S");
                st.insert(path);
            }
        }
    }
    return st.size();
}