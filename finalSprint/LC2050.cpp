#include <bits/stdc++.h>
using namespace std;

int minimumTime(int n,
                vector<vector<int>> &relations,
                vector<int> &time)
{

    vector<vector<int>> adj(n + 1);

    vector<int> indegree(n + 1, 0);

    for (auto &r : relations)
    {
        int u = r[0];
        int v = r[1];
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    vector<int> finishTime(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        finishTime[i] = time[i - 1];
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {

            finishTime[neighbor] =
                max(finishTime[neighbor],
                    finishTime[node] + time[neighbor - 1]);

            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    return *max_element(finishTime.begin(), finishTime.end());
}