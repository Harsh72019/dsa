#include<bits/stdc++.h>
using namespace std;


vector<int> bellmanFord(int V, vector<vector<pair<int, int>>> &adj, int src)
{
    vector<int> dist(V , INT_MAX);
    dist[src] = 0;
    
    for(int i = 0 ; i < V - 1 ; i++)
    {
        for(int j = 0 ; j < V ; j++)
        {
            for(auto it : adj[j])
            {
                int adjNode = it.first;
                int adjDistance = it.second;
                if(dist[j] + adjDistance < dist[adjNode]  && dist[j] != INT_MAX)
                {
                    dist[adjNode] = dist[j] + adjDistance;
                }
            }
        }
    }
    
    return dist;
}

