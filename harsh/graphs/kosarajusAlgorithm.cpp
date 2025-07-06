#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs2(it, adj, visited);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }

    vector<vector<int>> reverseGraph(V);

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        reverseGraph[v].push_back(u);
    }

    vector<bool> visited2(V, false);

    int count = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited2[node])
        {
            dfs2(node, reverseGraph, visited2);
            count++;
        }
    }
    return count;
}