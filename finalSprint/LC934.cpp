#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    void dfs(int r, int c, vector<vector<int>>& grid, queue<pair<int,int>>& q) {
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1)
            return;

        grid[r][c] = -1;          
        q.push({r, c});          

        for (int i = 0; i < 4; i++)
            dfs(r + dx[i], c + dy[i], grid, q);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>> q;

        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, q);
                    found = true;
                }
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int flips = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc])
                        continue;

                    if (grid[nr][nc] == 1)
                        return flips;   

                    if (grid[nr][nc] == 0) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            flips++;
        }

        return -1;
    }
};
