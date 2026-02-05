#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, int k)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<vector<bool>>> visited(
        rows, vector<vector<bool>>(cols, vector<bool>(k + 1, false)));

    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, k});
    visited[0][0][k] = true;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {-1, 1, 0, 0};

    while (!q.empty())
    {
        auto ele = q.front();
        int row = get<0>(ele);
        int col = get<1>(ele);
        int length = get<2>(ele);
        int remainingK = get<3>(ele);
        q.pop();

        if (row == rows - 1 && col == cols - 1) 
            return length;

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dx[i];
            int nCol = col + dy[i];

            if (nRow < 0 || nRow >= rows || nCol < 0 || nCol >= cols)
                continue;

            int newK = remainingK - grid[nRow][nCol];
            if (newK < 0)
                continue;

            if (visited[nRow][nCol][newK])
                continue;

            visited[nRow][nCol][newK] = true;
            q.push({nRow, nCol, length + 1, newK});
        }
    }

    return -1;
}