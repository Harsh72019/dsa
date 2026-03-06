#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int freshOranges = 0;
        queue<pair<int, int>> q;
        int timeSwept = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 2)
                    q.push({row, col});
                if (grid[row][col] == 1)
                    freshOranges++;
            }
        }

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        if (q.empty())
        {
            if (freshOranges != 0)
                return -1;
            return 0;
        }

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto [row, col] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nRow = dx[i] + row;
                    int nCol = dy[i] + col;
                    if (nRow < 0 || nRow >= rows || nCol < 0 || nCol >= cols || grid[nRow][nCol] != 1)
                        continue;
                    q.push({nRow, nCol});
                    grid[nRow][nCol] = 2;
                    freshOranges--;
                }
            }
            if (!q.empty())
                timeSwept++;
        }

        if (freshOranges == 0)
            return timeSwept;
        return -1;
    }
};