#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int node, int n)
    {
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); i++)
        {
            int nNode = adj[node][i];
            if (!visited[nNode])
                dfs(adj, visited, nNode, n);
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }
        vector<int> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i, n);
                count++;
            }
        }
        return count;
    }
};