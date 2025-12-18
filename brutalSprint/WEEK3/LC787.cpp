#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto &f : flights)
    {
        adj[f[0]].push_back({f[1], f[2]});
    }

    vector<int> minCost(n, INT_MAX);
    queue<pair<int, int>> q; // {city, cost}

    q.push({src, 0});
    minCost[src] = 0;

    int stops = 0;

    while (!q.empty() && stops <= k)
    {
        int sz = q.size();
        while (sz--)
        {
            auto [city, cost] = q.front();
            q.pop();

            for (auto &[next, price] : adj[city])
            {
                if (cost + price < minCost[next])
                {
                    minCost[next] = cost + price;
                    q.push({next, minCost[next]});
                }
            }
        }
        stops++;
    }

    return minCost[dst] == INT_MAX ? -1 : minCost[dst];
}