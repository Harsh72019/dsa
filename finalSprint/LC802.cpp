#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> adj(n);
    vector<int> outDegree(n, 0);
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        outDegree[i] = graph[i].size();
        for (int j = 0; j < graph[i].size(); j++)
        {
            adj[graph[i][j]].push_back(i);
        }

        if (outDegree[i] == 0)
            q.push(i);
    }

    vector<bool> safe(n, false);

    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        safe[ele] = true;

        for (int parent : adj[ele])
        {
            outDegree[parent]--;
            if (outDegree[parent] == 0)
                q.push(parent);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (safe[i])
            ans.push_back(i);
    }

    sort(ans.begin(), ans.end());
    return ans;
}