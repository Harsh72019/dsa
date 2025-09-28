#include<bits/stdc++.h>
using namespace std;

bool dfsCycleCheck(int node , vector<int> adj[], vector<bool>& visited, int parent) {
    visited[node] = true;

    for(auto neighbor : adj[node])
    {
        if(!visited[neighbor])
        {
            if(dfsCycleCheck(neighbor, adj, visited, node))
                return true;
        }
        else if(neighbor != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycleCheck(i, adj, visited, -1)) {
                return true; 
            }
        }
    }
    return false; 
}