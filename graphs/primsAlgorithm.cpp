#include <bits/stdc++.h>
using namespace std;

pair<vector<pair<int, int>>, int> primsAlgorithm(vector<vector<pair<int, int>>> &edges, int n) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<bool> visited(n, false);
    vector<pair<int, int>> mst;
    int cost = 0;

    pq.push({0, {0, -1}});

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int currentNode = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        if (!visited[currentNode]) {
            visited[currentNode] = true;
            if (parent != -1) {
                mst.push_back({parent, currentNode});
                cost += currentCost;
            }

            for (auto it : edges[currentNode]) {
                if (!visited[it.first]) {
                    pq.push({it.second, {it.first, currentNode}});
                }
            }
        }
    }

    return {mst, cost};
}
