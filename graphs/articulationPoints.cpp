#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<vector<int>>& adj,
             vector<bool>& visited, vector<int>& tin, vector<int>& low,
             unordered_set<int>& articulationPoints)
    {
        visited[node] = true;
        tin[node] = low[node] = timer++;
        int children = 0;

        for (int neigh : adj[node]) {
            if (neigh == parent) continue;

            if (!visited[neigh]) {
                dfs(neigh, node, adj, visited, tin, low, articulationPoints);
                low[node] = min(low[node], low[neigh]);

                // Non-root articulation point
                if (low[neigh] >= tin[node] && parent != -1)
                    articulationPoints.insert(node);

                children++;
            } else {
                low[node] = min(low[node], tin[neigh]);
            }
        }

        // Root articulation point
        if (parent == -1 && children > 1)
            articulationPoints.insert(node);
    }

public:
    vector<int> findArticulationPoints(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> tin(n), low(n);
        vector<bool> visited(n, false);
        unordered_set<int> articulationPoints;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, tin, low, articulationPoints);
            }
        }

        return vector<int>(articulationPoints.begin(), articulationPoints.end());
    }
};
