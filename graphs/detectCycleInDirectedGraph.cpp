#include <bits/stdc++.h>
using namespace std;



 bool dfs(vector<int> adj[], int node, vector<bool>& visited, vector<bool>& pathVisited) {
        visited[node] = true;
        pathVisited[node] = true;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(adj, it, visited, pathVisited)) return true;
            } else if (pathVisited[it]) {
                return true;
            }
        }

        pathVisited[node] = false; 
        return false;
    }

    bool isCyclic(int N, vector<int> adj[]) {
        vector<bool> visited(N, false);
        vector<bool> pathVisited(N, false);

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, pathVisited)) return true;
            }
        }

        return false;
    }