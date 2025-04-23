#include<bits/stdc++.h>
using namespace std;

void solve(int row, int col, vector<vector<int>> &grid, vector<string> &ans, string currentPath, vector<vector<int>> &visited) {
    int n = grid.size();

    if (row == n - 1 && col == n - 1) {
        ans.push_back(currentPath);
        return;
    }

    
    if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] == 0 || visited[row][col])
        return;

    visited[row][col] = 1;

    currentPath.push_back('D');
    solve(row + 1, col, grid, ans, currentPath, visited);
    currentPath.pop_back();

   
    currentPath.push_back('R');
    solve(row, col + 1, grid, ans, currentPath, visited);
    currentPath.pop_back();


    currentPath.push_back('L');
    solve(row, col - 1, grid, ans, currentPath, visited);
    currentPath.pop_back();

    currentPath.push_back('U');
    solve(row - 1, col, grid, ans, currentPath, visited);
    currentPath.pop_back();

    visited[row][col] = 0;
}

vector<string> findPath(vector<vector<int>> &grid) {
    vector<string> ans;
    string currentPath = "";
    int currentRow = 0;
    int currentCol = 0;
    int n = grid.size();

    if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0)
        return ans;

    vector<vector<int>> visited(n, vector<int>(n, 0));
    solve(currentRow, currentCol, grid, ans, currentPath, visited);
    return ans;
}