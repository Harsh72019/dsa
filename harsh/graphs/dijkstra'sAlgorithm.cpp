#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &edges, int n, int src)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        for (auto it : edges[node])
        {
            int adjNode = it.first;
            int adjDistance = it.second;
            if (dist[node] + adjDistance < dist[adjNode])
            {
                dist[adjNode] = dist[node] + adjDistance;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main()
{
    int n = 3;
    vector<vector<pair<int, int>>> edges(n);
    edges[0].push_back({1, 1});
    edges[1].push_back({0, 1});
    edges[0].push_back({2, 6});
    edges[2].push_back({0, 6});
    edges[1].push_back({2, 3});
    edges[2].push_back({1, 3});
    cout << "Dijkstra's Algorithm: ";
    vector<int> dist = dijkstra(edges, n, 0);
    for (auto it : dist)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
