#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, int node, vector<int> &state)
{
    if (state[node] == 1)
        return false;
    if (state[node] == 2)
        return true;

    state[node] = 1;

    for (int nei : adj[node])
    {
        if (!dfs(adj, nei, state))
            return false;
    }

    state[node] = 2;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto &p : prerequisites)
        adj[p[0]].push_back(p[1]);

    vector<int> state(numCourses, 0);

    for (int i = 0; i < numCourses; i++)
    {
        if (state[i] == 0)
        {
            if (!dfs(adj, i, state))
                return false;
        }
    }
    return true;
}