#include<bits/stdc++.h>
using namespace std;
int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        deque<tuple<int,int,int>> dq;
        vector<vector<int>> bestSoFar(rows, vector<int>(cols, INT_MAX));

        dq.push_front({0, 0, 0});
        bestSoFar[0][0] = 0;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!dq.empty()) {
            auto [row, col, cost] = dq.front();
            dq.pop_front();

            if (cost > bestSoFar[row][col]) continue;

            if (row == rows - 1 && col == cols - 1)
                return cost;

            for (int i = 0; i < 4; i++) {
                int nRow = row + dx[i];
                int nCol = col + dy[i];

                if (nRow < 0 || nRow >= rows || nCol < 0 || nCol >= cols)
                    continue;

                int newCost = cost + (grid[row][col] != i + 1);

                if (newCost < bestSoFar[nRow][nCol]) {
                    bestSoFar[nRow][nCol] = newCost;
                    if (grid[row][col] == i + 1)
                        dq.push_front({nRow, nCol, newCost});
                    else
                        dq.push_back({nRow, nCol, newCost});
                }
            }
        }
        return -1;
    }