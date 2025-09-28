#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int adjDistance = it[1];
            if (dist[node] + adjDistance < dist[adjNode])
            {
                dist[adjNode] = dist[node] + adjDistance;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}