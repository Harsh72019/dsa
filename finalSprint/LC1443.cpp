#include <bits/stdc++.h>
using namespace std;

int dfs(int node,
        int parent,
        vector<vector<int>> &adj,
        vector<bool> &hasApple)
{

    int totalTime = 0;

    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;

        int childTime = dfs(neighbor, node, adj, hasApple);

        if (childTime > 0 || hasApple[neighbor])
        {
            totalTime += childTime + 2;
        }
    }

    return totalTime;
}

int minTime(int n,
            vector<vector<int>> &edges,
            vector<bool> &hasApple)
{

    // Build adjacency list
    vector<vector<int>> adj(n);
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    return dfs(0, -1, adj, hasApple);
}