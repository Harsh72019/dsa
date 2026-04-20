#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>> &sources)
    {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<tuple<int, int, int, int>> q;

        for (auto it : sources)
        {
            visited[it[0]][it[1]] = 1;
            ans[it[0]][it[1]] = max(ans[it[0]][it[1]], it[2]);
            q.push({it[0], it[1], it[2], 1});
        }

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto [row, col, color, itr] = q.front();
                q.pop();

                if (visited[row][col] < itr)
                    continue;

                for (int i = 0; i < 4; i++)
                {
                    int nRow = row + dx[i];
                    int nCol = col + dy[i];
                    if (nRow < 0 || nCol < 0 || nRow >= n || nCol >= m)
                        continue;

                    if (visited[nRow][nCol] == 0)
                    {
                        visited[nRow][nCol] = itr + 1;
                        ans[nRow][nCol] = color;
                        q.push({nRow, nCol, color, itr + 1});
                    }
                    else if (visited[nRow][nCol] == itr + 1)
                    {
                        if (color > ans[nRow][nCol])
                        {
                            ans[nRow][nCol] = color;
                            q.push({nRow, nCol, color, itr + 1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};