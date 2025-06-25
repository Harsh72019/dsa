#include<bits/stdc++.h>
using namespace std;



vector<int> dijkstra(vector<vector<pair<int , int>>> &edges, int n, int src)
{
    vector<int> dist(n , INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int , int>> pq;  // min heap
    pq.push({0 , src});

    while(!pq.empty())
    {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        for(auto it : edges[node])
        {
            int adjNode = it.first;
            int adjDistance = it.second;
            if(dist[node] + adjDistance < dist[adjNode])
            {
                dist[adjNode] = dist[node] + adjDistance;
                pq.push({dist[adjNode] , adjNode});
            }
        }
    }

    return dist;
}


int main(){
    // [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], 3, 0
    vector<vector<pair<int , int>>> edges = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    vector<int> dist = dijkstra(edges , 3 , 0);
    for(auto it : dist)
    {
        cout << it << " ";
    }
    return 0;
}