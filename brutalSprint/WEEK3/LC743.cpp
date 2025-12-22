#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);

    for (auto &t : times)
    {
        adj[t[0]].push_back({t[1], t[2]});
    }

    // Min-heap: {time, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    vector<int> dist(n + 1, INT_MAX);

    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty())
    {
        auto [time, node] = pq.top();
        pq.pop();

        if (time > dist[node])
            continue;

        for (auto &[next, wt] : adj[node])
        {
            if (dist[next] > time + wt)
            {
                dist[next] = time + wt;
                pq.push({dist[next], next});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
            return -1;
        ans = max(ans, dist[i]);
    }

    return ans;
}