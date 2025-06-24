#include<bits/stdc++.h>
using namespace std;

 vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        vector<pair<int, int>> adj[N];
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].emplace_back(v, wt);
        }

        vector<int> topo;
        vector<bool> visited(N, false);

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (auto &[nei, wt] : adj[node]) {
                if (!visited[nei]) {
                    dfs(nei);
                }
            }
            topo.push_back(node);
        };

        for (int i = 0; i < N; i++) {
            if (!visited[i])
                dfs(i);
        }

        reverse(topo.begin(), topo.end()); 

        vector<int> dist(N, 1e9);
        dist[0] = 0;  

        for (int node : topo) {
            if (dist[node] != 1e9) {
                for (auto &[nei, wt] : adj[node]) {
                    if (dist[node] + wt < dist[nei]) {
                        dist[nei] = dist[node] + wt;
                    }
                }
            }
        }

        // Step 4: Replace unreachable nodes with -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }