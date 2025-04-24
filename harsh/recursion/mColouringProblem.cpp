#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], vector<vector<int>>& graph, int n, int col) {
    for (int k = 0; k < n; k++) {
        if (graph[node][k] == 1 && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, vector<vector<int>>& graph, int m, int n, int color[]) {
    if (node == n) return true;

    for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, graph, n, i)) {
            color[node] = i;
            if (solve(node + 1, graph, m, n, color)) return true;
            color[node] = 0; 
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& edges, int m, int n) {
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (auto& edge : edges) {
        graph[edge[0]][edge[1]] = 1;
        graph[edge[1]][edge[0]] = 1;
    }

    int color[n] = {0};

    return solve(0, graph, m, n, color);
}