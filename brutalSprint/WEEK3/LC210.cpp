#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &path, vector<int> &visited)
{
    if (visited[node] == 1)
        return false;
    if (visited[node] == 2)
        return true;
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!dfs(adj[node][i], adj, path, visited))
            return false;
    }
    visited[node] = 2;
    path.push_back(node);
    return true;
}
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto it : prerequisites)
    {
        adj[it[0]].push_back(it[1]);
    }
    vector<int> visited(numCourses, false);
    vector<int> ans;
    for (int i = 0; i < numCourses; i++)
    {
        if (!dfs(i, adj, ans, visited))
            return {};
    }
    return ans;
}