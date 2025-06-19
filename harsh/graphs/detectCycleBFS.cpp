#include<bits/stdc++.h>
using namespace std;


    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfsCycleCheck(i, adj, visited)) {
                    return true; 
                }
            }
        }
        return false; 
    }

    bool bfsCycleCheck(int start, vector<int> adj[], vector<bool>& visited) {
        queue<pair<int, int>> q; 
        q.push({start, -1});
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    return true;
                }
            }
        }

        return false;
    }
