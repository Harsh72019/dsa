#include <bits/stdc++.h>
using namespace std;

int solver(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (row == triangle.size() - 1)
        return triangle[row][col];

    if (dp[row][col] != INT_MAX)
        return dp[row][col];

    int down = triangle[row][col] + solver(row + 1, col, triangle, dp);
    int downRight = triangle[row][col] + solver(row + 1, col + 1, triangle, dp);

    return dp[row][col] = min(down, downRight);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    return solver(0, 0, triangle, dp);
}


int main(){
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle);
    return 0;
}