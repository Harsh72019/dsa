#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto it : times)
    {
        int source = it[0];
        int destination = it[1];
        int time = it[2];
        adj[source].push_back({destination, time});
    }

    vector<int> minTime(n + 1, INT_MAX);

    minTime[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int time = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int currentNode = it.first;
            int currentTime = it.second;
            if (minTime[currentNode] > time + currentTime)
            {
                minTime[currentNode] = time + currentTime;
                pq.push({time + currentTime, currentNode});
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i < minTime.size(); i++)
    {
        if (minTime[i] == INT_MAX)
            return -1;
        ans = max(minTime[i], ans);
    }
    return ans;
}