#include<bits/stdc++.h>
using namespace std;

  int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int dx[4] = {+1, +1, -1, -1};
        const int dy[4] = {+1, -1, -1, +1};

        static int dp[500][500][4][2][2];
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                for (int d=0; d<4; d++)
                    for (int t=0; t<2; t++)
                        for (int k=0;k<2;k++)
                            dp[i][j][d][t][k] = -2; 

        auto inb = [&](int x, int y){ return x>=0 && x<n && y>=0 && y<m; };

        function<int(int,int,int,int,int)> dfs = [&](int x, int y, int d, int turned, int needIdx)->int {
            if (!inb(x,y)) return 0;
            int need = (needIdx==0? 2 : 0);
            if (grid[x][y] != need) return 0;
            int &memo = dp[x][y][d][turned][needIdx];
            if (memo != -2) return memo;

            int nextNeedIdx = 1 - needIdx;
            int best = 1;

            int nx = x + dx[d], ny = y + dy[d];
            best = max(best, 1 + dfs(nx, ny, d, turned, nextNeedIdx));

            if (!turned) {
                int nd = (d + 1) & 3; 
                int tx = x + dx[nd], ty = y + dy[nd];
                best = max(best, 1 + dfs(tx, ty, nd, 1, nextNeedIdx));
            }
            return memo = best;
        };

        int ans = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j] != 1) continue;
                ans = max(ans, 1);
                for (int d=0; d<4; d++){
                    int nx = i + dx[d], ny = j + dy[d];
                    ans = max(ans, 1 + dfs(nx, ny, d, 0, 0));
                }
            }
        }
        return ans;
    }