#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &isConnected, int node, vector<bool> &visited)
{
    visited[node] = true;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (isConnected[node][i] == 1 && !visited[i])
            dfs(isConnected, i, visited);
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(isConnected, i, visited);
        }
    }
    return count;
}