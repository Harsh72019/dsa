#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
public:
    vector<int> par, sz;
    Disjoint(int n)
    {
        sz.resize(n, 1);
        par.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
    }
    int findparent(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = findparent(par[u]);
    }
    void unionBySize(int x, int y)
    {
        int xp = findparent(x), yp = findparent(y);
        if (xp == yp)
            return;
        if (sz[xp] > sz[yp])
        {
            sz[xp] += sz[yp];
            par[yp] = xp;
        }
        else
        {
            sz[yp] += sz[xp];
            par[xp] = yp;
        }
    }
};

int largestIsland(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int nodes = rows * cols;
    Disjoint ds(nodes);

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    for(int i = 0 ;i  <rows ; i++)
    {
        for(int j = 0 ; j < cols ; j++)
        {
            if(grid[i][j] == 1)
            {
                for(int k = 0 ; k < 4 ; k++)
                {
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1)
                    {
                        int node1 = i * cols + j;
                        int node2 = nr * cols + nc;
                        ds.unionBySize(node1 , node2);
                    }
                }
            }
        }
    }

    int ans = *max_element(ds.sz.begin() , ds.sz.end());
    
    for(int i = 0 ;i < rows ; i++)
    {
        for(int j = 0 ; j < cols ;j ++)
        {
            if(grid[i][j]== 0)
            {
                unordered_set<int> parent;
                for(int k = 0 ; k < 4 ; k++)
                {
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1)
                    {
                        int node = nr * cols + nc;
                        parent.insert(ds.findparent(node));
                    }
                }

                int size = 1;
                for(auto it : parent)
                {
                    size += ds.sz[it];
                }
                ans = max(ans , size);
            }
        }
    }

    return ans;

}
